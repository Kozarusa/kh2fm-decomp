#!/usr/bin/env python3
"""Round-27 helper: disassemble a probe ELF against the original target range.

Usage (under WSL):
    python3 r27_diff.py <address> <probe-elf> [<probe-elf> ...]

Prints the compiled disassembly beside the target disassembly and a word-level
diff summary, so a variant's defect can be read off directly instead of guessed
from the probe's hex summary line.
"""
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

ELF = Path('/work/SLPM_666.75')   # container-side path
STAGE = Path('/root/kh2fm-build')  # host path, mounted at /work
IMAGE = 'kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
WORKSPACE = Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')


def disasm(path, start, stop):
    env = dict(os.environ, MSYS_NO_PATHCONV='1')
    out = subprocess.run(
        ['docker', 'run', '--rm', '--platform', 'linux/amd64',
         '-v', f'{STAGE}:/work', '-w', '/work', IMAGE,
         'bash', '-lc',
         f'/opt/ps2/gcc/bin/ee-objdump -d --start-address=0x{start:08x} '
         f'--stop-address=0x{stop:08x} {path}'],
        capture_output=True, text=True, env=env)
    rows = []
    for line in out.stdout.splitlines():
        parts = line.split('\t')
        if len(parts) >= 3 and ':' in parts[0]:
            rows.append((parts[0].strip(), ' '.join((parts[1].split() + parts[2].split()))))
    return rows, out.stdout + out.stderr


def main():
    address = int(sys.argv[1], 16)
    targets = {r['address']: r for r in json.loads(
        (WORKSPACE / 'analysis/final-mix/worker-coordination/worker-b/round-27/claim.json'
         ).read_text())['claimed_addresses']}
    size = targets['%08x' % address]['size']
    orig = disasm(str(ELF), address, address + size)
    print(f'===== target {address:08x} ({size} bytes)')
    for a, t in orig[0]:
        print(f'  {a}  {t}')

    for path in sys.argv[2:]:
        cp = path.replace('/root/kh2fm-build', '/work')
        blob = Path(path).read_bytes()
        rows = disasm(cp, address, address + size)
        print(f'===== compiled {Path(path).name} ({len(blob)} bytes file)')
        for a, t in rows[0]:
            print(f'  {a}  {t}')
        if not rows[0]:
            print(rows[1][:400])
        tw = [t for _, t in orig[0]]
        cw = [t for _, t in rows[0]]
        n = 0
        for i in range(max(len(tw), len(cw))):
            a = tw[i] if i < len(tw) else '<none>'
            b = cw[i] if i < len(cw) else '<none>'
            if a.split()[0] != b.split()[0]:
                n += 1
                print(f'  [{i:02d}] target {a!r}  vs  compiled {b!r}')
        print(f'  differing opcode words: {n} (target {len(tw)} words, compiled {len(cw)} words)')


if __name__ == '__main__':
    main()