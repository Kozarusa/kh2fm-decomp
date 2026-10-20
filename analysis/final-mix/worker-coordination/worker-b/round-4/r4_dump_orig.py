#!/usr/bin/env python3
"""Round-3 helper: verify bound original ranges and emit their bytes + disassembly.

Usage: python3 r4_dump_orig.py <targets-file-without-extension>

Reads <name>.targets.json beside this file, extracts each declared original range
from tools/kh2-reference/SLPM_666.75, verifies the ELF SHA256 and every range
SHA256, then writes:
  <addr>.orig.hex    raw bytes (hex, one line)
  r4_ranges.txt      "<start> <end>" lines, LF-only (pinned ee-objdump input)
and, when --disasm is passed, the pinned-objdump disassembly of all ranges into
r4_orig_disasm.txt.

EE virtual address -> file offset: MAIN_VADDR 0x00100000 maps to MAIN_FOFF 0x001000.
"""
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
WS = HERE.parents[4]
# The project root is AGENTS/Codex; tools/ lives in AGENTS/Public (moved 2026-10-08).
# This helper is run both under WSL and under Windows python, so try both spellings.
ELF = Path('/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
if not ELF.exists():
    ELF = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
IMAGE = 'kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
STAGE = '/root/kh2fm-build'
CONTAINER_DIR = '/work/analysis/final-mix/worker-coordination/worker-b/round-4'


def addr_to_offset(address: int) -> int:
    return address - 0x100000 + 0x1000


def main() -> int:
    name = sys.argv[1]
    targets = json.loads((HERE / (name + '.targets.json')).read_text())
    blob = ELF.read_bytes()
    digest = hashlib.sha256(blob).hexdigest()
    print(f'ELF sha256 {digest}')
    assert digest == targets['original_elf_sha256'], 'original ELF hash mismatch'

    lines, ranges, ok = [], [], True
    for t in targets['targets']:
        address, size = t['address'], t['size']
        off = addr_to_offset(int(address, 16))
        data = blob[off:off + size]
        got = hashlib.sha256(data).hexdigest()
        good = got == t['original_range_sha256']
        ok &= good
        print(f"{address} size={size} sha256={got} {'OK' if good else 'MISMATCH'}")
        (HERE / f'{address}.orig.hex').write_text(data.hex() + '\n', newline='')
        ranges.append(f"{address} {t['end']}")
        lines.append(f'{address} {size} {got}')

    (HERE / 'r4_ranges.txt').write_text('\n'.join(ranges) + '\n', newline='')
    (HERE / 'r4_range_hashes.txt').write_text('\n'.join(lines) + '\n', newline='')

    if '--disasm' in sys.argv:
        # Disassemble each verified range from the original ELF with the pinned
        # ee-objdump. The ELF lives on the Windows workspace, which the round-1
        # helper mounts at /work inside the image.
        helper = '/work/analysis/final-mix/worker-coordination/worker-b/objdump_orig_inner.sh'
        ranges = ('/work/analysis/final-mix/worker-coordination/worker-b/'
                  'round-4/r4_ranges.txt')
        out = subprocess.run(
            ['docker', 'run', '--rm', '--platform', 'linux/amd64',
             '-v', '/mnt/c/Users/KoZa/Documents/AGENTS/Codex:/work', '-v', '/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools:/work/tools', '-w', '/work', IMAGE,
             'bash', helper, ranges],
            capture_output=True, text=True)
        text = out.stdout + out.stderr
        (HERE / 'r4_orig_disasm.txt').write_text(text, newline='')
        print(f'wrote r4_orig_disasm.txt ({len(text)} bytes)')
    return 0 if ok else 1


if __name__ == '__main__':
    raise SystemExit(main())