"""Print aligned original and compiled instruction words for one saved proof."""
import json
from pathlib import Path
import sys

row = json.loads(Path(sys.argv[1]).read_text())['rows'][0]
original = bytes.fromhex(row['target_hex'])
compiled = bytes.fromhex(row['compiled_hex'])
for offset in range(0, max(len(original), len(compiled)), 4):
    a = original[offset:offset+4]
    b = compiled[offset:offset+4]
    if a == b and '--all' not in sys.argv:
        continue
    print(f'{int(row["address"], 16)+offset:08x} original={int.from_bytes(a, "little"):08x} compiled={int.from_bytes(b, "little"):08x}')
