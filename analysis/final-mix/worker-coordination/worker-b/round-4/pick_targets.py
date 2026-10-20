"""Round-4 target picker.

Ranks unclaimed, unregistered ranges that carry verified pseudocode, but screens out
the shape classes that resisted rounds 2 and 3:

  * non-zero stack frame  -> the 16-byte callee-save stride class (00310620)
  * prologue-only body    -> the empty cleanup-stub class (00100338 / 001003b0 / 00101d38)
  * anything already attempted by worker-b

Everything else is ranked by size so the budget goes to ranges that are actually
reachable with the pinned compiler.
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

# worker-b round-1/2/3 attempts (solved or blocked) - never re-propose these
ATTEMPTED = set("""
002bc2e8 0017ee68 00310620 00180c88 002f3bb8 0019c0f8
002f8870 00152598 002d5c20 00308da0 0028af90 0028ac98 001c8a90 00100338
001003b0 00101d38 00161410 001d6850 00241f20
""".split())

# ranges the primary or another worker holds
RESERVED = set("""
00132850 00154558 001565c0 0016a158 0017c0a0 0018db38 0019e6e8 001c9df8
001d6ec8 00281f90 002bcbf0 002c1950 002db610 002eb778 002eb9d8 002ecd0 00303c48 00307f68
00104210 001c7ab8 00288398
""".split())


def load_registration():
    cv = json.load(open(CV))
    rows = cv["rows"] if isinstance(cv, dict) else cv
    reg = {str(r["address"]).lower() for r in rows}
    return reg


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
            except Exception:
                continue
            a = str(d.get("address", "")).lower()
            if a:
                jl[a] = d
    return jl


def words(blob, addr, n):
    base = addr - MAIN_VADDR + MAIN_FOFF
    return [int.from_bytes(blob[base + 4 * i:base + 4 * i + 4], "big") for i in range(n)]


def classify(ws):
    """Return (verdict, tags).  verdict is 'skip' or 'keep'."""
    tags = []
    w0 = ws[0]
    # addiu sp,sp,-N  == opcode 0x27bd with a non-zero negative immediate
    if (w0 >> 16) == 0x27BD:
        imm = w0 & 0xFFFF
        if imm != 0:
            tags.append("frame%d" % ((-imm) & 0xFFFF))
            return "skip", tags
    if (w0 >> 26) == 0x0F:  # lui
        return "skip", tags + ["lui-first"]
    if len(ws) <= 3 and (ws[-1] >> 26) == 0x02 and (ws[-1] & 0x3F) == 0x08:
        tags.append("tiny-tail")
    # count call/jump density as a rough difficulty signal
    ncall = sum(1 for w in ws if (w >> 26) == 0x03)
    njump = sum(1 for w in ws if (w >> 26) in (0x02, 0x05))
    tags.append("call=%d" % ncall)
    tags.append("br=%d" % njump)
    if ncall == 0 and njump == 0:
        tags.append("LEAF-BRANCHLESS")
    return "keep", tags


def main():
    reg = load_registration()
    size, name = load_layout()
    jl = load_pseudocode()
    print("registered rows:", len(reg), " layout ranges:", len(size), " pseudocode:", len(jl))

    blob = open(ISO, "rb").read()
    taken = reg | ATTEMPTED | RESERVED
    cands = [a for a in jl if a not in taken and a in size]

    keep = []
    for a in cands:
        n = size[a]
        if n % 4 or n < 8 or n > 96:
            continue
        ws = words(blob, int(a, 16), n // 4)
        verdict, tags = classify(ws)
        if verdict == "keep":
            keep.append((n, a, tags))

    # rank: branchless leaves first (cheapest class), then by size
    keep.sort(key=lambda e: (0 if "LEAF-BRANCHLESS" in e[2] else 1, e[0], e[1]))
    print("candidates after screening:", len(keep))
    print()
    for n, a, tags in keep[: int(sys.argv[1]) if len(sys.argv) > 1 else 30]:
        d = jl[a]
        body = " ".join(str(d.get("code") or d.get("body") or "").split())
        print("%s %4dB %-26s %s" % (a, n, name.get(a, "")[:26], ",".join(tags)))
        print("      sig : %s" % d.get("signature", "")[:110])
        print("      code: %s" % body[:300])
    print()
    print("tag histogram:", Counter(t for _, _, ts in keep for t in ts).most_common(12))


if __name__ == "__main__":
    main()
