#!/usr/bin/env python3
"""Read-only byte coverage report for the KH2FM native build. Run: python -I coverage.py"""
import json
import sqlite3
import sys
from collections import defaultdict

ROOT = r"C:\Users\KoZa\Documents\AGENTS"
LAYOUT = ROOT + r"\Public\tools\kh2-reference\layout.tsv"
FM = ROOT + r"\Codex\analysis\final-mix"
RANGES = FM + r"\native-build\compiler-range-verification.json"
BUILD = FM + r"\native-build\native-build-verification.json"
INPUTS = FM + r"\native-inputs.json"
VECTORS = FM + r"\vector-programs.json"
DB = FM + r"\worker-coordination\recovery-queue.sqlite3"


def load(path):
    with open(path, "r", encoding="utf-8") as handle:
        return json.load(handle)


def read_layout():
    rows = {}
    with open(LAYOUT, "r", encoding="utf-8") as handle:
        for line in handle:
            line = line.rstrip("\r\n")
            if not line or line.startswith("#"):
                continue
            parts = line.split("\t")
            if parts[0] == "addr":
                continue
            rows[parts[0]] = int(parts[2])
    return rows


def pct(part, whole):
    return "%.1f%%" % (100.0 * part / whole) if whole else "n/a"


def table(header, rows, left=1):
    out = ["| " + " | ".join(header) + " |",
           "| " + " | ".join(["---"] * left + ["---:"] * (len(header) - left)) + " |"]
    for row in rows:
        out.append("| " + " | ".join(row) + " |")
    return "\n".join(out)


def main():
    layout = read_layout()
    ranges = load(RANGES)
    build = load(BUILD)
    declared_count = len(layout)
    declared_bytes = sum(layout.values())

    accepted_addrs = [r["address"] for r in ranges if r.get("unmodified_compiled_symbol_match")]
    accepted_count = len(accepted_addrs)
    accepted_bytes = sum(layout.get(a, 0) for a in accepted_addrs)
    missing = [a for a in accepted_addrs if a not in layout]
    fb_count = declared_count - accepted_count
    fb_bytes = declared_bytes - accepted_bytes

    failed = []
    if accepted_count != build["unmodified_compiled_symbol_matches"]:
        failed.append("(a) accepted count %d != unmodified_compiled_symbol_matches %d"
                      % (accepted_count, build["unmodified_compiled_symbol_matches"]))
    if len(ranges) + build["original_fallback_range_count"] != declared_count:
        failed.append("(b) %d verified ranges + %d fallback != %d layout rows"
                      % (len(ranges), build["original_fallback_range_count"], declared_count))
    if missing:
        failed.append("(c) %d accepted addresses not in layout.tsv" % len(missing))

    t1 = [
        ["Declared code ranges", "{:,}".format(declared_count), "{:,}".format(declared_bytes), "100.0%"],
        ["Accepted C++ (exact symbol match)", "{:,}".format(accepted_count), "{:,}".format(accepted_bytes), pct(accepted_bytes, declared_bytes)],
        ["Fallback (rest of layout.tsv, includes zero_padded ranges)", "{:,}".format(fb_count), "{:,}".format(fb_bytes), pct(fb_bytes, declared_bytes)],
    ]
    # queue database, read-only
    by_pri = defaultdict(lambda: [0, 0])
    by_state = defaultdict(lambda: [0, 0])
    db = sqlite3.connect("file:" + DB + "?mode=ro", uri=True)
    try:
        for address, metadata, state in db.execute("select address, metadata, state from targets"):
            if state == "accepted":
                continue
            meta = json.loads(metadata)
            size = int(meta.get("bytes", 0))
            pri = meta.get("priority")
            by_pri[pri][0] += 1
            by_pri[pri][1] += size
            by_state[state][0] += 1
            by_state[state][1] += size
    finally:
        db.close()
    for pri in sorted(by_pri, key=lambda x: (x is None, x)):
        c, b = by_pri[pri]
        t1.append(["Queue fallback, priority %s" % pri, "{:,}".format(c), "{:,}".format(b), pct(b, declared_bytes)])
    order = ["ready", "reserved", "submitted"]
    for state in order + sorted(s for s in by_state if s not in order):
        if state in by_state:
            c, b = by_state[state]
            t1.append(["Queue fallback, state %s" % state, "{:,}".format(c), "{:,}".format(b), pct(b, declared_bytes)])

    print("## Table 1: main executable (SLPM_666.75) code coverage\n")
    print(table(["Row", "Ranges", "Bytes", "% of declared code bytes"], t1))
    print()
    print("Queue rows exclude targets already in state accepted; priority and state rows are fallback ranges still tracked by the queue.")

    inputs = load(INPUTS)
    t2 = []
    for name, info in inputs.items():
        if name == "SLPM_666.75":
            continue
        size = info.get("size") if isinstance(info, dict) else None
        t2.append([name, "{:,}".format(size) if size is not None else "n/a", "not in build proof"])
    vectors = load(VECTORS)
    vsum = sum(v.get("size", 0) for v in vectors)
    t2.append(["VU programs (%d)" % len(vectors), "{:,}".format(vsum), "not in build proof"])
    print("\n## Table 2: other native inputs\n")
    print(table(["Module", "Size (bytes)", "Status"], t2, left=1).replace("| ---: |\n", "| --- |\n", 1))
    print("\nDeclared code ranges are the denominator; data, tables and undiscovered code are not included.")

    if failed:
        for f in failed:
            print("CHECK FAILED: " + f)
        sys.exit(1)
    print("\nChecks passed: accepted count == unmodified_compiled_symbol_matches (%d); %d verified ranges + %d fallback == %d layout rows."
          % (accepted_count, len(ranges), build["original_fallback_range_count"], declared_count))


if __name__ == "__main__":
    main()

