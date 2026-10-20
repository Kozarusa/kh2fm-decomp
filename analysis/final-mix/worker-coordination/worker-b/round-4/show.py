"""Dump pseudocode for a list of addresses, or for the callers of a callee."""
import json, re, sys

JL = "analysis/final-mix/native-pseudocode/main.jsonl"
want = set(a.lower() for a in sys.argv[1:])

for line in open(JL, encoding="utf-8", errors="replace"):
    line = line.strip()
    if not line:
        continue
    try:
        o = json.loads(line)
    except ValueError:
        continue
    if o["address"].lower() in want:
        print(f"===== {o['address']}  {o.get('name')}  sig={o.get('signature')}")
        print(o.get("code", ""))