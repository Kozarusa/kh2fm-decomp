"""Round-12 target picker.

Learned in rounds 5 and 6 about this pinned compiler (kh2-local/ps2-compiler:3.2-ee-040921):

  * functions that open with `addiu sp,sp,-N` and contain at least one `sd`/`ld` reproduce
    almost word-for-word from ordinary C - that is where the budget should go;
  * frameless sibling-call thunks (argument setup + a bare `j`) do NOT reproduce: this
    compiler always allocates a 16-byte frame around a tail call, so 001002a0, 0030f690,
    0030f6a0 and 0030f6b0 are permanently 1-2 words out in pure C;
  * anything containing COP1/CO2/COP2 words (0x11/0x12/0x13) is a float function and the
    Ghidra records for those are frequently wrong (they do not distinguish swc1 from sw);
  * a `lui`-first body means a global address materialisation - cheap, but the symbol value
    must be written with this compiler's non-carry-adjusted `lui`/`lw` convention.

This picker therefore keeps only framed, integer-only, pseudocode-backed ranges that nobody
has attempted yet.
"""
import json
import sys
from collections import Counter

ROOT = "C:/Users/KoZa/Documents/AGENTS/Codex"
CV = ROOT + "/analysis/final-mix/native-build/compiler-range-verification.json"
JP = ROOT + "/analysis/final-mix/native-pseudocode/main.jsonl"
LTS = "C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/layout.tsv"
ISO = "C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75"

MAIN_VADDR = 0x00100000
MAIN_FOFF = 0x001000

# every worker-b address ever attempted (rounds 1-11)
ATTEMPTED = set("""00100338 001003b0 00101d38 00104210 00109e30 00114b78 0014b950 00150de0 00152598 001576e8
00161410 0017dec0 0017ee68 00180c88 001995f8 0019c0f8 001ac310 001ba060 001c7ab8 001c8a90
001c8e00 001d6850 001e7230 00229d40 00241f20 00242500 00288398 0028ac98 0028af90 002bc2e8
002d5c20 002e8290 002f3bb8 002f8870 00308da0 00310620 001002a0 0016e8f8 001ac700 0021cda0
00288610 002f1e00 0030a300 0030f690 0030f6a0 0030f6b0 003062a0 003062c0 003062e0 00306300
00366db0 002954e0 00308cd0 002b99a0 00196170 0023fb00
003062a0 003062c0 003062e0 00306300 00366db0 002954e0 00308cd0 002b99a0 00196170 0023fb00
00196300 001d9d00 001b92d0 00305ce0 00305e20 0019fd88 002ead20 002ecdb0 00322968 00173270
00185a98 002b6ab8
00171348 00171378 00171e58 00180770 00185a68 0023fb28 002ba3b8 002ef340 00305e48 00307f40 003197f8 0031f940
002b81ec 002b8214 003068d8 0030ec28 00315418 003155c0 002f1898 0018f858 001b81e8 001231f8 0016fb00 001dc488
0030a2d0 0018f218 001dc4b8 001de948 001de978 001e0128 001e0158 001e0188 001e01b8 001e6250 002bef78 002f0798 002f07c8 001050d8 0016fac8 00171810""".split())

RESERVED = set("""00132850 00154558 001565c0 0016a158 0016b518 0017c0a0 001814b8 0018db38 0019e6e8
001b0148 001c0a80 001c9df8 001d6ec8 002006b0 00242a28 00281f90 0029e2f8 002bcbf0 002c1950
002cff50 002db610 002ddbb8 002eb068 002eb778 002eb9d8 002ec9d0 002ecd0 00303c48 00307f68""".split())


def load_primary_reserved():
    """Primary's live claim, re-read every round so we stay disjoint."""
    p = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/primary-claim.json"
    try:
        d = json.load(open(p, encoding="utf-8"))
        return {str(a).lower() for a in d.get("addresses", [])}
    except Exception:
        return set()


def load_registration():
    cv = json.load(open(CV))
    rows = cv["rows"] if isinstance(cv, dict) else cv
    return {str(r["address"]).lower() for r in rows}


def load_layout():
    size, name = {}, {}
    with open(LTS, encoding="utf-8", errors="replace") as f:
        for line in f:
            if line.startswith("#"):
                continue
            p = line.rstrip("\n").split("\t")
            if len(p) < 3 or len(p[0]) != 8:
                continue
            try:
                size[p[0]] = int(p[2])
                name[p[0]] = p[3] if len(p) > 3 else ""
            except ValueError:
                pass
    return size, name


def load_pseudocode():
    jl = {}
    with open(JP, encoding="utf-8", errors="replace") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                d = json.loads(line)
            except ValueError:
                continue
            a = str(d.get("address", "")).lower()
            if len(a) == 8:
                jl[a] = d
    return jl


def words(blob, address, n):
    off = address - MAIN_VADDR + MAIN_FOFF
    raw = blob[off:off + n * 4]
    return [int.from_bytes(raw[i:i + 4], "little") for i in range(0, len(raw), 4)]


def classify(ws):
    tags = []
    op0 = ws[0] >> 26
    # must open with a real frame push: addiu sp,sp,-N
    if not (op0 == 0x09 and ((ws[0] >> 16) & 0x1F) == 29 and (ws[0] & 0x8000)):
        return "skip", ["no-frame"]
    frame = (ws[0] & 0xFFFF)
    tags.append("frame=%d" % (0x10000 - frame))
    if not any(((w >> 26) in (0x3F, 0x37) and ((w >> 21) & 0x1F) == 29) for w in ws):
        return "skip", tags + ["no-stack-word"]
    for w in ws:
        op = w >> 26
        if op in (0x11, 0x12, 0x13, 0x31, 0x35, 0x39, 0x3D):
            return "skip", tags + ["cop1"]
        if op == 0x2D:
            return "skip", tags + ["premul"]
        if op == 0x01 and ((w >> 16) & 0x1F) in (0, 1):
            return "skip", tags + ["bltz"]
    ncall = sum(1 for w in ws if (w >> 26) == 0x03)
    njump = sum(1 for w in ws if (w >> 26) in (0x02, 0x05))
    tags.append("call=%d" % ncall)
    tags.append("br=%d" % njump)
    if njump == 0:
        tags.append("NO-BRANCH")
    return "keep", tags


def main():
    reg = load_registration()
    size, name = load_layout()
    jl = load_pseudocode()
    print("registered rows:", len(reg), " layout ranges:", len(size), " pseudocode:", len(jl))
    blob = open(ISO, "rb").read()
    taken = reg | ATTEMPTED | RESERVED | load_primary_reserved()
    cands = [a for a in jl if a not in taken and a in size]
    keep = []
    for a in cands:
        n = size[a]
        if n % 4 or n < 20 or n > 120:
            continue
        verdict, tags = classify(words(blob, int(a, 16), n // 4))
        if verdict == "keep":
            keep.append((n, a, tags))
    keep.sort(key=lambda e: (0 if "NO-BRANCH" in e[2] else 1, e[0], e[1]))
    print("candidates after screening:", len(keep))
    print()
    for n, a, tags in keep[:int(sys.argv[1]) if len(sys.argv) > 1 else 30]:
        d = jl[a]
        body = " ".join(str(d.get("code") or d.get("body") or "").split())
        print("%s %4dB %-26s %s" % (a, n, name.get(a, "")[:26], ",".join(tags)))
        print("      sig : %s" % d.get("signature", "")[:110])
        print("      code: %s" % body[:300])
    print()
    print("tags:", Counter(t for _, _, ts in keep for t in ts).most_common(12))


if __name__ == "__main__":
    main()