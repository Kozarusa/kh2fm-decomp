"""Side-by-side instruction diff for one probe_fm_source.py verification file.

Advisory analysis only: the compiler gate stays probe_fm_source.py's own
complete-range byte comparison.

    python show_diff.py <source.cpp> [address ...]
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from disasm_r5900 import decode  # noqa: E402


def main():
    source = Path(sys.argv[1])
    wanted = sys.argv[2:]
    data = json.loads(source.with_suffix('.verification.json').read_text())
    for row in data['rows']:
        if wanted and row['address'] not in wanted:
            continue
        flag = 'MATCH' if row['exact_match'] else 'MISMATCH'
        print(f"=== {row['address']}  {flag}  compiled={row['compiled_size']} "
              f"target={row['target_size']} ghidra_body={row['ghidra_body_size']} "
              f"boundary_agreement={row['boundary_agreement']}")
        if row['exact_match']:
            continue
        target = bytes.fromhex(row['target_hex'])
        compiled = bytes.fromhex(row['compiled_hex'])
        for offset in range(0, max(len(target), len(compiled)), 4):
            word = target[offset:offset + 4]
            other = compiled[offset:offset + 4]
            here = decode(int.from_bytes(word, 'little')) if len(word) == 4 else '---'
            there = decode(int.from_bytes(other, 'little')) if len(other) == 4 else '---'
            same = '  ' if word == other else '**'
            print(f'{same} +{offset:04x} {word.hex() if word else "----":8} {here:<30}| {there}')


if __name__ == '__main__':
    main()