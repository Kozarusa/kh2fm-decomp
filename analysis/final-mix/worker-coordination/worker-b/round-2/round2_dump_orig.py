#!/usr/bin/env python3
"""Round-2 helper: verify the six bound original ranges and emit their bytes.

Reads targets.json beside this file, extracts each declared original range from
tools/kh2-reference/SLPM_666.75, verifies the ELF SHA256 and each range SHA256,
and writes <addr>.orig.hex / <addr>.orig.txt plus a combined ranges file used by
the pinned ee-objdump disassembly step.
"""
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
WS = HERE.parents[4]
TARGETS = json.loads((HERE / 'targets.json').read_text())
# The project root is AGENTS/Codex; tools/ lives in AGENTS/Public (moved 2026-10-08).
# This helper is run both under WSL and under Windows python, so try both spellings.
ELF = Path('/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
if not ELF.exists():
    ELF = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')


def addr_to_offset(address: int) -> int:
    """Map an EE virtual address to a file offset in the original ELF.

    MAIN_VADDR 0x00100000 maps to MAIN_FOFF 0x001000 (tools/common.py).
    """
    return address - 0x100000 + 0x1000


def main() -> int:
    blob = ELF.read_bytes()
    digest = hashlib.sha256(blob).hexdigest()
    expected = TARGETS['original_elf_sha256']
    print(f'ELF sha256 {digest}')
    assert digest == expected, 'original ELF hash mismatch'
    ranges = []
    ok = True
    for target in TARGETS['targets']:
        address = target['address']
        size = target['size']
        offset = addr_to_offset(int(address, 16))
        data = blob[offset:offset + size]
        got = hashlib.sha256(data).hexdigest()
        good = got == target['original_range_sha256']
        ok &= good
        print(f"{address} size={size} sha256={got} {'OK' if good else 'MISMATCH'}")
        (HERE / f'{address}.orig.hex').write_text(data.hex() + '\n', newline='')
        ranges.append(f"{address} {target['end']}")
    (HERE / 'round2_ranges.txt').write_text('\n'.join(ranges) + '\n', newline='')
    return 0 if ok else 1


if __name__ == '__main__':
    raise SystemExit(main())
