#!/usr/bin/env python3
"""Build a probe range-override file for compiler-behaviour test slots.

The pinned probe harness sizes each row from layout boundaries unless a range
override is supplied, so compiler-behaviour probes (frame layout, register
allocation, block ordering) can be parked on real original ranges whose bytes
are irrelevant: only the *compiled* output is read back.

    python r2_grid.py <slot-count> <size> [<first-address>]

Writes round-2/r2_grid_override.json listing consecutive slots of <size> bytes
starting at <first-address> (default 0x00309988) with the sha256 of the original
bytes each slot covers, and prints the address/size pairs to use.
"""
import hashlib
import json
import sys
from pathlib import Path

ELF = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
MAIN_FOFF = 0x1000
MAIN_VADDR = 0x100000
DEFAULT_FIRST = 0x00309988


def main(argv: list) -> int:
    count = int(argv[0])
    size = int(argv[1])
    first = int(argv[2], 16) if len(argv) > 2 else DEFAULT_FIRST
    blob = ELF.read_bytes()
    rows = []
    for index in range(count):
        address = first + index * size
        offset = address - MAIN_VADDR + MAIN_FOFF
        chunk = blob[offset:offset + size]
        assert len(chunk) == size, (hex(address), offset)
        rows.append({'address': f'{address:08x}', 'body_bytes': size,
                     'original_range_sha256': hashlib.sha256(chunk).hexdigest()})
    out = Path(__file__).resolve().parent / 'r2_grid_override.json'
    out.write_text(json.dumps(rows, indent=2) + '\n')
    print(f'override: {out}  slots={count} size={size} first={first:08x}')
    print(' '.join(row['address'] for row in rows))
    return 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv[1:]))
