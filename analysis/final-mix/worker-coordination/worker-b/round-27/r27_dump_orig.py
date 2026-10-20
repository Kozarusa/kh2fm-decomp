#!/usr/bin/env python3
"""Round-27 helper: verify this round's claimed fallback ranges and emit bytes + disassembly.

Same source of truth as rounds 23 and 26:
  original ELF  AGENTS/Public/tools/kh2-reference/SLPM_666.75
                sha256 d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87
  layout.tsv    read-only if present; the CRLF-terminated reference copy is used too
  targets       round-27/claim.json (this round's own claim)

EE vaddr -> file offset: MAIN_VADDR 0x00100000 maps to MAIN_FOFF 0x001000.

Clone lesson carried from round 26: BOTH the output filenames and the path arguments
passed to objdump_orig_inner.sh must be this round's. Sed on the rN_ prefix alone
leaves the previous round's path argument in place.

A second, distinct defect was found while setting this round up. Docker Desktop on
this host does not accept the WSL-style `/mnt/c/...` source used by the older rounds:
the bind mount silently comes up empty and bash then reports
`objdump_orig_inner.sh: No such file or directory`. The mount source must be the
Windows form `C:/Users/...`, and MSYS_NO_PATHCONV=1 must be set so git-bash does not
rewrite the container-side `/work` paths. Both are applied below.

Usage:  python3 r27_dump_orig.py [--disasm]
Writes: r27_ranges.txt, r27_range_hashes.txt, <addr>.orig.hex, r27_orig_disasm.txt
"""
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROUND = 'round-27'
ELF = Path('/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
if not ELF.exists():
    ELF = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
WSL_LAYOUT = Path('/root/kh2fm-build/layout.tsv')
REF_LAYOUT = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/layout.tsv')
ELF_SHA = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
IMAGE = 'kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
CLAIM = HERE / 'claim.json'
WB = 'analysis/final-mix/worker-coordination/worker-b'


def addr_to_offset(address: int) -> int:
    return address - 0x100000 + 0x1000


def layout_rows():
    rows = {}
    for lay in (WSL_LAYOUT, REF_LAYOUT):
        if not lay.exists():
            continue
        # layout.tsv is CRLF-terminated: strip both CR and LF
        for line in lay.read_text().splitlines():
            line = line.strip()
            if line.startswith('#') or line.startswith('addr\t'):
                continue
            f = line.split('\t')
            if len(f) >= 4:
                rows[f[0].strip()] = (f[1].strip(), int(f[2]), f[3].strip())
        if rows:
            break
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
    print(f'layout rows available: {len(lay)}')
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

    (HERE / 'r27_ranges.txt').write_text('\n'.join(ranges) + '\n', newline='')
    (HERE / 'r27_range_hashes.txt').write_text('\n'.join(lines) + '\n', newline='')

    if '--disasm' in sys.argv:
        # MSYS_NO_PATHCONV keeps git-bash from rewriting the container-side paths
        # (-w /work and /work/... arguments) into host paths.
        env = dict(os.environ, MSYS_NO_PATHCONV='1', MSYS2_ARG_CONV_EXCL='*')
        out = subprocess.run(
            ['docker', 'run', '--rm', '--platform', 'linux/amd64',
             '-v', r'C:/Users/KoZa/Documents/AGENTS/Codex:/work',
             '-v', r'C:/Users/KoZa/Documents/AGENTS/Public/tools:/work/tools',
             '-w', '/work', IMAGE,
             'bash', f'/work/{WB}/objdump_orig_inner.sh',
             f'/work/{WB}/{ROUND}/r27_ranges.txt'],
            capture_output=True, text=True, env=env)
        text = out.stdout + out.stderr
        (HERE / 'r27_orig_disasm.txt').write_text(text, newline='')
        print(f'wrote r27_orig_disasm.txt ({len(text)} bytes)')
        if 'No such file' in text:
            print('WARNING: disassembly contains a missing-file message')
    return 0 if ok else 1


if __name__ == '__main__':
    raise SystemExit(main())