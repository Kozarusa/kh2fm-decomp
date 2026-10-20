"""Mine the already-byte-exact corpus for the idioms the six assigned targets need.

Question 1 (00109e30, 00242500): when a function has an if/else whose arms both
end in a call, which arm does this pinned GCC make the fall-through, and does the
source's `== 0` / `!= 0` polarity predict it?  The assigned targets both want the
NON-ZERO arm inline; the registered sources have the zero arm inline.

Question 2 (001ac310): does a recovered exact function address a field through a
`puVar1 = param_1 + N` alias rather than through param_1 itself?

Question 3 (001576e8): is there an exact function that passes a nested call
straight into another call's argument list?

Runs entirely offline: reads the verification JSONs and the .cpp sources that
already exist in the workspace.  No compiler, no Docker.
"""

import json
import os
import re
from collections import defaultdict

RE = "analysis/final-mix/recovery-experiments"
STAGE_LIST = os.path.join(RE, "fm_worker_b_round3_%s_solved.cpp")


def words(hexstr):
    """verification JSON hex is little-endian bytes; reverse each 4-byte group."""
    b = bytes.fromhex(hexstr)
    return [int.from_bytes(b[i:i + 4], "little") for i in range(0, len(b), 4)]


def is_jal(w):
    return (w >> 26) == 3


def is_j(w):
    return (w >> 26) == 2


def is_beq(w):
    return (w >> 26) == 4 and ((w >> 6) & 0x1f) == 0          # beq rt,rs,off


def is_bne(w):
    return (w >> 26) == 5


def is_beqz_zero_reg(w):
    """beq with one operand being $zero."""
    rs = (w >> 21) & 0x1f
    rt = (w >> 16) & 0x1f
    return (w >> 26) == 4 and (rs == 0 or rt == 0)


def first_call_after(ws, i):
    """index of the first jal/j at or after i, or None."""
    for k in range(i, len(ws)):
        if is_jal(ws[k]) or is_j(ws[k]):
            return k
    return None


# ------------------------------------------------------------------ corpus
def load_exact_corpus():
    """address -> (source_path, compiled_hex, target_hex) for every exact row."""
    exact = {}
    for fn in os.listdir(RE):
        if not fn.endswith(".verification.json"):
            continue
        path = os.path.join(RE, fn)
        try:
            doc = json.load(open(path))
        except Exception:
            continue
        src = doc.get("source")
        if not src:
            continue
        rows = doc.get("rows") or []
        for row in rows:
            if row.get("exact_match"):
                exact.setdefault(row["address"], (src, row.get("compiled_hex", ""),
                                                 row.get("target_hex", "")))
    return exact


def load_sources():
    """path -> text for every .cpp we can see."""
    out = {}
    for fn in os.listdir(RE):
        if fn.endswith(".cpp"):
            out[fn] = open(os.path.join(RE, fn), encoding="utf-8", errors="replace").read()
    return out


FUNC_RE = re.compile(r"^[A-Za-z_][\w:<>,\s\*]*?\bfunc_([0-9a-f]{8})\s*\(", re.M)


def body_of(text, addr):
    """Crude but sufficient: the text from `func_<addr>(` to the matching brace."""
    m = re.search(r"\bfunc_%s\s*\(" % addr, text)
    if not m:
        return None
    i = text.index("{", m.end())
    depth = 0
    for j in range(i, len(text)):
        if text[j] == "{":
            depth += 1
        elif text[j] == "}":
            depth -= 1
            if depth == 0:
                return text[m.start():j + 1]
    return text[m.start():]


def analyse_polarity(exact, sources):
    """Correlate source polarity with which arm GCC inlined."""
    hits = []
    for addr, (src, chex, thex) in sorted(exact.items()):
        name = os.path.basename(src)
        text = sources.get(name)
        if not text:
            continue
        body = body_of(text, addr)
        if not body:
            continue
        # source must contain an if/else where both arms contain a call
        if body.count("func_") < 3:
            continue
        if "if" not in body or "else" not in body:
            continue
        ws = words(chex)
        if len(ws) < 8:
            continue
        # find the conditional branch in the compiled code
        br = None
        for i, w in enumerate(ws):
            if is_beqz_zero_reg(w) and (is_beq(w) or is_bne(w)):
                br = i
                break
        if br is None:
            continue
        delay = br + 1
        if delay >= len(ws):
            continue
        inline_call = first_call_after(ws, delay)
        if inline_call is None:
            continue
        # the out-of-line arm is whatever the branch targets; approximate by
        # requiring exactly one other call after inline_call
        rest = [k for k in range(inline_call + 1, len(ws)) if is_jal(ws[k]) or is_j(ws[k])]
        if len(rest) != 1:
            continue
        # source polarity
        pol = None
        if re.search(r"if\s*\([^)]*==\s*0\s*\)", body):
            pol = "== 0"
        elif re.search(r"if\s*\([^)]*!=\s*0\s*\)", body):
            pol = "!= 0"
        elif re.search(r"if\s*\([^)]*==\s*0x0\s*\)", body):
            pol = "== 0"
        hits.append((addr, pol, "beq" if is_beq(ws[br]) else "bne", name))
    return hits


def main():
    exact = load_exact_corpus()
    sources = load_sources()
    print(f"exact rows in corpus: {len(exact)}   readable sources: {len(sources)}")

    hits = analyse_polarity(exact, sources)
    print(f"\nif/else-both-arms-call functions with an exact match: {len(hits)}")

    tally = defaultdict(int)
    for addr, pol, br, name in hits:
        tally[(pol, br)] += 1
    print("source polarity / emitted branch -> count:")
    for k in sorted(tally, key=lambda x: (str(x[0]), str(x[1]))):
        print(f"   {str(k[0]):>6}  {k[1]}  {tally[k]}")

    print("\nsample (address, polarity, branch, source file):")
    for row in hits[:40]:
        print("   ", row)

    with open("analysis/final-mix/worker-coordination/worker-b/round-4/"
              "polarity_census.txt", "w", newline="\n") as f:
        f.write(f"exact rows: {len(exact)}\n")
        f.write(f"if/else both-arms-call exact functions: {len(hits)}\n\n")
        for k in sorted(tally, key=lambda x: (str(x[0]), str(x[1]))):
            f.write(f"{k[0]} {k[1]} {tally[k]}\n")
        f.write("\n")
        for row in hits:
            f.write(" ".join(str(x) for x in row) + "\n")
    print("\nwrote round-4/polarity_census.txt")


if __name__ == "__main__":
    main()