"""Find sibling functions in main.jsonl that share the assigned targets' call patterns.

For each assigned target we know its distinctive callees. A sibling that already
recovered byte-exact uses the same C++ idiom, so its source shape is the recipe we
can read offline while the compiler is down.
"""
import json, re, collections, sys

JL = "analysis/final-mix/native-pseudocode/main.jsonl"

# distinctive callees per assigned target (from the decoded disassembly)
SIGS = {
    "00109e30": ["00133f80", "00133f60"],
    "00242500": ["001058e8"],
    "001ac310": ["0027e5e0", "0027e3a8"],
    "001e7230": ["0023b028"],
    "001576e8": ["00155d58", "00138c10"],
    "0014b950": ["0012fa90", "00305448"],
}
TARGETS = set(SIGS)


def callees(code):
    """callee names referenced by FUN_ calls"""
    return set(re.findall(r"FUN_([0-9a-f]{8})", code))


rows = []
for line in open(JL, encoding="utf-8", errors="replace"):
    line = line.strip()
    if not line:
        continue
    try:
        o = json.loads(line)
    except ValueError:
        continue
    c = callees(o.get("code", ""))
    rows.append((o["address"], o.get("name"), c, o))

print(f"pseudocode entries: {len(rows)}")

# 1. how many OTHER functions call each distinctive callee
for tgt, sig in SIGS.items():
    print(f"\n=== {tgt}  distinctive callees {sig}")
    for s in sig:
        hits = [r[0] for r in rows if s in r[2] and r[0] != tgt]
        print(f"  FUN_{s}: {len(hits)} other callers  {hits[:12]}")

# 2. signature-shape histogram for each target's own code, to find near-identical twins
def norm(code):
    """strip identifiers to keep only call order / control shape"""
    c = re.sub(r"FUN_[0-9a-f]{8}", "F", code)
    c = re.sub(r"(DAT|local|uVar|param|in_|extraout)_?[0-9a-f]*", "V", c)
    c = re.sub(r"\s+", " ", c)
    return c


for tgt in TARGETS:
    tr = next(r for r in rows if r[0] == tgt)
    n = norm(tr[3]["code"])
    twins = [r[0] for r in rows if r[0] != tgt and norm(r[3]["code"]) == n]
    print(f"\n{tgt}: exact-shape twins among recovered pseudocode: {len(twins)} {twins[:10]}")