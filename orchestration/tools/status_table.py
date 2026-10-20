#!/usr/bin/env python3
"""Print the STATUS.md "Accepted state" table from the latest checkpoint. Read-only. Run: python -I status_table.py"""
import glob
import json
import os
import sys

FM = r"C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix"


def load(path):
    with open(path, "r", encoding="utf-8") as handle:
        return json.load(handle)


def main():
    status = load(FM + r"\worker-coordination\compiler-status.json")
    phase = status["last_accepted_phase"]
    if phase.startswith("primary-"):
        phase = phase[len("primary-"):]
    found = sorted(glob.glob(os.path.join(FM, "primary-%s-checkpoint-*.json" % phase)))
    if not found:
        print("CHECK FAILED: no checkpoint primary-%s-checkpoint-*.json" % phase)
        sys.exit(1)
    checkpoint = load(found[-1])
    build = load(FM + r"\native-build\native-build-verification.json")

    matches = checkpoint["active_exact_matches"]
    if matches != build["unmodified_compiled_symbol_matches"]:
        print("CHECK FAILED: checkpoint matches %d != build proof %d" % (matches, build["unmodified_compiled_symbol_matches"]))
        sys.exit(1)
    rows = [
        ("Complete, equal-size instruction matches", "{:,}".format(matches)),
        ("Registered C++ ranges (includes 4 padding cases)", "{:,}".format(build["cpp_range_count"])),
        ("Original-byte fallback ranges still remaining", "{:,}".format(build["original_fallback_range_count"])),
        ("Verified staged compiler inputs", "{:,}".format(build["source_input_files_verified_against_workspace"])),
        ("Cumulative recovery bundles passing", "see O3 step 8"),
        ("Switch batches passing", "see O3 step 8"),
    ]
    print("| Measure | Value |")
    print("| --- | ---: |")
    for name, value in rows:
        print("| %s | %s |" % (name, value))
    print()
    print("Latest checkpoint: %s" % os.path.relpath(found[-1], os.path.dirname(FM)).replace("\\", "/"))


if __name__ == "__main__":
    main()
