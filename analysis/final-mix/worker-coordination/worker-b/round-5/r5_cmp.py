#!/usr/bin/env python3
"""Word-level diff between a probe verification row and its pinned original range.

The probe's JSON stores each 4-byte group little-endian (confirmed against
`27bdf-ff0` == `addiu sp,sp,-16`), so both sides are compared as raw groups and
decoded only for display.

Usage: python3 r5_cmp.py <stem> [<stem> ...]
       python3 r5_cmp.py --addr 0014b950 <stem>
"""
import binascii
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
EXP = HERE.parents[2] / 'recovery-experiments'
ADDRS = ['00109e30', '0014b950', '001ac310', '001e7230', '00242500']


def groups(hexstr):
    h = hexstr.strip()
    return [h[i:i + 8] for i in range(0, len(h), 8)]


def orig_hex(addr):
    raw = binascii.unhexlify((HERE / f'{addr}.orig.hex').read_text().strip())
    return ''.join(raw[i:i + 4][::-1].hex() for i in range(0, len(raw), 4))


def main():
    args = sys.argv[1:]
    addr = None
    if args[:1] == ['--addr']:
        addr = args[1]
        args = args[2:]
    bad = 0
    for stem in args:
        for base in (EXP, HERE):
            vj = base / f'{stem}.verification.json'
            if vj.exists():
                break
        else:
            print(f'!! no verification json for {stem}')
            continue
        v = json.loads(vj.read_text())
        row = v['rows'][0] if isinstance(v, dict) and 'rows' in v else v
        a = addr or next((x for x in ADDRS if x in stem), None)
        oh = row.get('target_hex') or orig_hex(a)
        ch = row.get('compiled_hex') or ''
        og, cg = groups(oh), groups(ch)
        diff = [i for i in range(max(len(og), len(cg)))
                if (og[i] if i < len(og) else None) != (cg[i] if i < len(cg) else None)]
        bad += len(diff)
        print(f'== {stem}: exact={row.get("exact_match")} '
              f'boundary={row.get("boundary_agreement")} '
              f'size={row.get("compiled_size")}/{row.get("target_size")} '
              f'diffwords={len(diff)} at {[d * 4 for d in diff]}')
        if len(diff) <= 12:
            for i in diff:
                o = og[i] if i < len(og) else '-'
                c = cg[i] if i < len(cg) else '-'
                print(f'   +{i * 4:3d} w{i:2d} orig {o}  got {c}')
    print(f'total differing words: {bad}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
