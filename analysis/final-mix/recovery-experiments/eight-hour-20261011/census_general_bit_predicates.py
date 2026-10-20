"""Recognize the proven flag predicate across register and field-load variants."""
import hashlib
import json
from pathlib import Path
import sqlite3
import struct
import sys

base = Path(__file__).resolve().parent
workspace = base.parents[3]
area = workspace / 'analysis/final-mix'
reference = workspace.parent / 'Public/tools/kh2-reference'
sys.path.insert(0, str(reference / 'tools'))
from common import load_elf_image, read_elf_vaddr, load_boundaries

original = load_elf_image(reference / 'SLPM_666.75')
assert hashlib.sha256(original[0]).hexdigest() == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
accepted = {r['address'] for r in json.loads((area / 'native-build/compiler-range-verification.json').read_text())}
db = sqlite3.connect('file:' + str(area / 'worker-coordination/recovery-queue.sqlite3') + '?mode=ro', uri=True)
states = {a: (state, queue) for a, state, queue in db.execute('select address,state,queue from targets')}
db.close()
matches = []
load_types = {32: 's8', 33: 's16', 35: 'u32', 36: 'u8', 37: 'u16'}
for boundary in load_boundaries(reference / 'layout.tsv'):
    if boundary.size != 36:
        continue
    data = read_elf_vaddr(original, boundary.addr, boundary.size)
    w = struct.unpack('<9I', data)
    op, source, flags = w[0] >> 26, (w[0] >> 21) & 31, (w[0] >> 16) & 31
    if op not in load_types or source != 4 or flags in [0, 2, 5]:
        continue
    if w[1] != (4 << 26 | flags << 21 | 5) or w[2] != 0x0000102d:
        continue
    mask = (w[3] >> 16) & 31
    if w[3] != (9 << 26 | mask << 16 | 1) or mask in [0, 2, 5, flags]:
        continue
    if w[4] != (5 << 21 | mask << 16 | mask << 11 | 4):
        continue
    masked = (w[5] >> 11) & 31
    if masked == 0 or w[5] != (flags << 21 | mask << 16 | masked << 11 | 36):
        continue
    if w[6] != (masked << 16 | 2 << 11 | 43) or w[7:] != (0x03e00008, 0):
        continue
    address = f'{boundary.addr:08x}'
    matches.append(dict(address=address, field_type=load_types[op], offset=struct.unpack('<h', struct.pack('<H', w[0] & 0xffff))[0],
                        flags_register=flags, mask_register=mask, masked_register=masked,
                        accepted=address in accepted, state=states.get(address),
                        original_range_sha256=hashlib.sha256(data).hexdigest()))
assert any(r['address'] == '0028b1c0' for r in matches), 'Proven positive control missing'
path = base / 'general-bit-predicate-census.json'
assert not path.exists()
path.write_text(json.dumps(dict(positive_control='0028b1c0', scope='Complete declared 36-byte guarded scalar flag predicates', matches=matches), indent=2) + '\n')
print(f'General guarded-bit census: {len(matches)} members; {sum(not r["accepted"] for r in matches)} unaccepted.')
for row in matches:
    if not row['accepted']:
        print(json.dumps(row))
