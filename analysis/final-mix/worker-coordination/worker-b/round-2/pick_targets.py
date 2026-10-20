import json

ROOT = "C:/Users/KoZa/Documents/AGENTS/Codex"
CV = ROOT + "/analysis/final-mix/native-build/compiler-range-verification.json"
JP = ROOT + "/analysis/final-mix/native-pseudocode/main.jsonl"
LTS = "C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/layout.tsv"

cv = json.load(open(CV))
rows = cv["rows"] if isinstance(cv, dict) else cv
reg = set()
exact = set()
for r in rows:
    a = str(r["address"]).lower()
    reg.add(a)
    if r.get("unmodified_compiled_symbol_match") or r.get("normalized_match"):
        exact.add(a)
print("registered rows:", len(reg), "matching:", len(exact))

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
print("layout ranges:", len(size))

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

CLAIMED = set("""00132850 00154558 001565c0 0016a158 0017c0a0 0018db38 0019e6e8 001c9df8
001d6ec8 00281f90 002bcbf0 002c1950 002db610 002eb778 002eb9d8 002ec9d0 00303c48 00307f68
002bc2e8 0017ee68 00310620 00180c88 002f3bb8 0019c0f8
00104210 001c7ab8 001d6850 00241f20""".split())

cands = [a for a in jl if a not in reg and a not in CLAIMED and a in size]
print("unregistered, unclaimed, with pseudocode:", len(cands))
cands.sort(key=lambda a: (size.get(a, 9999), a))
print("\nsmallest 30:")
for a in cands[:30]:
    d = jl[a]
    print("  %s  %4d B  %-28s callees=%s  status=%s" % (
        a, size[a], d.get("name", "")[:28], len(d.get("callees") or []), d.get("status", "")))