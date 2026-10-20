"""Rank probe variants by how far they are from the target bytes.

Reads the `<source>.verification.json` files the probe harness writes next to
each variant source, so it needs no compiler and no WSL.

    python score.py <dir> [<address>] [limit]

Distance = number of 4-byte words that differ inside the overlapping range,
plus the words present in only one side.  Lower is better; 0 is byte-exact.
"""
import json
import sys
from pathlib import Path


def distance(target_hex, compiled_hex):
    t = bytes.fromhex(target_hex)
    c = bytes.fromhex(compiled_hex)
    n = max(len(t), len(c))
    same = sum(1 for i in range(0, n - 3, 4) if t[i:i + 4] == c[i:i + 4])
    words = (n + 3) // 4
    return words - same, len(t), len(c)


def main():
    root = Path(sys.argv[1])
    wanted = sys.argv[2] if len(sys.argv) > 2 else None
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 25
    rows = []
    for proof in sorted(root.glob("*.verification.json")):
        try:
            data = json.loads(proof.read_text())
        except Exception:
            continue
        for row in data.get("rows", []):
            if wanted and row["address"] != wanted:
                continue
            d, tsz, csz = distance(row["target_hex"], row["compiled_hex"])
            rows.append((d, row["address"], csz - tsz, proof.stem))
    rows.sort()
    for d, addr, dsz, name in rows[:limit]:
        print(f"{d:3d} words differ  {addr}  size delta {dsz:+4d}  {name}")
    if len(rows) > limit:
        print(f"... {len(rows)} probed rows total")


if __name__ == "__main__":
    main()