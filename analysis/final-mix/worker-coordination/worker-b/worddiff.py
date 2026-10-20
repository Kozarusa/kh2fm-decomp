"""Print the aligned target-vs-compiled word diff for one probed function.

    python worddiff.py <source.verification.json> <address>

Reads only the probe harness's own evidence file, so no compiler and no WSL
are required.  `=` marks a matching word, `!` a differing one, and a blank row
marks an insertion or deletion at that offset.
"""
import json
import sys
from pathlib import Path


def main():
    proof = Path(sys.argv[1])
    address = sys.argv[2]
    row = next(r for r in json.loads(proof.read_text())["rows"]
               if r["address"] == address)
    t = bytes.fromhex(row["target_hex"])
    c = bytes.fromhex(row["compiled_hex"])
    words = max(len(t), len(c)) // 4
    for i in range(words):
        tw = t[i * 4:i * 4 + 4]
        cw = c[i * 4:i * 4 + 4]
        mark = "=" if tw == cw else "!"
        print(f"{address[:8]}+{i * 4:04x}  {tw.hex() or '----'}  {cw.hex() or '----'}  {mark}")


if __name__ == "__main__":
    main()