#!/usr/bin/env python3
"""Round-2 helper: word-level diff between a probe row's compiled and target bytes.

Usage:
    python round2_diff.py <verification.json> [address ...]

Each row of the verification JSON carries compiled_hex and target_hex for a
declared native range. The two streams always have equal length, so the helper
reports the first differing word, every differing word offset, and the raw big
endian instruction word pairs for manual decoding.
"""
import json
import sys
from pathlib import Path


def words(hex_string: str):
    raw = bytes.fromhex(hex_string)
    assert len(raw) % 4 == 0, 'range is not word aligned'
    return [raw[i:i + 4][::-1].hex() for i in range(0, len(raw), 4)]


def diff(address: str, row: dict) -> None:
    compiled = words(row['compiled_hex'])
    target = words(row['target_hex'])
    print(f"##### {address} {row['symbol']} size={row['compiled_size']}"
          f"/{row['target_size']} exact={row['exact_match']}")
    if len(compiled) != len(target):
        print(f'  length mismatch: {len(compiled)} vs {len(target)} words')
    count = 0
    first = None
    for index, (c, t) in enumerate(zip(compiled, target)):
        if c != t:
            count += 1
            if first is None:
                first = index
            print(f'  +{index * 4:04x} w{index:2d}  T {t}   C {c}')
    print(f'  differing words: {count}  first differing word: {first}')
    print()


def main(argv: list[str]) -> int:
    data = json.loads(Path(argv[0]).read_text())
    wanted = set(argv[1:])
    for row in data['rows']:
        if wanted and row['address'] not in wanted:
            continue
        diff(row['address'], row)
    return 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv[1:]))
