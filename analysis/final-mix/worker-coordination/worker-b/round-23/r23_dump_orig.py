#!/usr/bin/env python3
"""Round-9 helper: verify the self-claimed fallback ranges and emit bytes + disassembly.

Same source of truth as round 5:
  original ELF  AGENTS/Public/tools/kh2-reference/SLPM_666.75
                sha256 d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87
  layout.tsv    /root/kh2fm-build/layout.tsv  (primary-owned, read-only here)
  targets       round-14/claim.json (this round's own claim)

EE vaddr -> file offset: MAIN_VADDR 0x00100000 maps to MAIN_FOFF 0x001000.

Usage:  python3 r23_dump_orig.py [--disasm]
Writes: r23_ranges.txt, r23_range_hashes.txt, <addr>.orig.hex, r23_orig_disasm.txt
"""
import hashlib
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ELF = Path('/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
if not ELF.exists():
    ELF = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
LAYOUT = Path('/root/kh2fm-build/layout.tsv')
ELF_SHA = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
IMAGE = 'kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
CLAIM = HERE / 'claim.json'


def addr_to_offset(address: int) -> int:
    return address - 0x100000 + 0x1000


def layout_rows():
    rows = {}
    if not LAYOUT.exists():
        return rows
    for line in LAYOUT.read_text().splitlines():
        if line.startswith('#') or line.startswith('addr\t'):
            continue
        f = line.split('\t')
        if len(f) >= 4:
            rows[f[0]] = (f[1], int(f[2]), f[3])
    return rows


def main() -> int:
    targets = {t['address']: t for t in json.loads(CLAIM.read_text())['claimed_addresses']}
    blob = ELF.read_bytes()
    digest = hashlib.sha256(blob).hexdigest()
    print(f'ELF sha256 {digest}')
    ok = digest == ELF_SHA
    if not ok:
        print('original ELF hash mismatch')

    lay = layout_rows()
    ranges, lines = [], []
    for a, t in targets.items():
        address, size = int(a, 16), t['size']
        off = addr_to_offset(address)
        data = blob[off:off + size]
        got = hashlib.sha256(data).hexdigest()
        end = '%08x' % (address + size)
        lay_ok = a in lay and lay[a][0] == end and lay[a][1] == size
        print(f'{a} size={size} end={end} sha256={got} '
              f'layout={lay.get(a)} {"OK" if lay_ok else "MISMATCH/ABSENT"}')
        (HERE / f'{a}.orig.hex').write_text(data.hex() + '\n', newline='')
        ranges.append(f'{a} {end}')
        lines.append(f'{a} {size} {got}')

    (HERE / 'r23_ranges.txt').write_text('\n'.join(ranges) + '\n', newline='')
    (HERE / 'r23_range_hashes.txt').write_text('\n'.join(lines) + '\n', newline='')

    if '--disasm' in sys.argv:
        out = subprocess.run(
            ['docker', 'run', '--rm', '--platform', 'linux/amd64',
             '-v', '/mnt/c/Users/KoZa/Documents/AGENTS/Codex:/work',
             '-v', '/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools:/work/tools',
             '-w', '/work', IMAGE,
             'bash', '/work/analysis/final-mix/worker-coordination/worker-b/'
                     'objdump_orig_inner.sh',
             '/work/analysis/final-mix/worker-coordination/worker-b/round-23/r23_ranges.txt'],
            capture_output=True, text=True)
        text = out.stdout + out.stderr
        (HERE / 'r23_orig_disasm.txt').write_text(text, newline='')
        print(f'wrote r23_orig_disasm.txt ({len(text)} bytes)')
    return 0 if ok else 1


if __name__ == '__main__':
    raise SystemExit(main())