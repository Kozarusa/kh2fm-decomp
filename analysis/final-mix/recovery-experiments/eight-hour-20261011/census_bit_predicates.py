"""Positive-control census for the exact guarded single-field flag predicate."""
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
proof = json.loads((base / 'eight_hour_0028b1c0_0_cpp.verification.json').read_text())['rows'][0]
assert proof['exact_match'] and proof['target_hex'] == proof['compiled_hex']
control = struct.unpack('<9I', bytes.fromhex(proof['target_hex']))
accepted = {r['address'] for r in json.loads((area / 'native-build/compiler-range-verification.json').read_text())}
db = sqlite3.connect('file:' + str(area / 'worker-coordination/recovery-queue.sqlite3') + '?mode=ro', uri=True)
states = {a: (state, queue) for a, state, queue in db.execute('select address,state,queue from targets')}
db.close()
matches = []
for boundary in load_boundaries(reference / 'layout.tsv'):
    if boundary.size != 36:
        continue
    data = read_elf_vaddr(original, boundary.addr, boundary.size)
    words = struct.unpack('<9I', data)
    if words[0] & 0xffff0000 != control[0] & 0xffff0000 or words[1:] != control[1:]:
        continue
    offset = struct.unpack('<h', struct.pack('<H', words[0] & 0xffff))[0]
    address = f'{boundary.addr:08x}'
    matches.append(dict(address=address, offset=offset, accepted=address in accepted,
                        state=states.get(address), original_range_sha256=hashlib.sha256(data).hexdigest()))
assert any(r['address'] == '0028b1c0' for r in matches), 'Positive control missing'
path = base / 'bit-predicate-family-census.json'
assert not path.exists()
path.write_text(json.dumps(dict(positive_control='0028b1c0', scope='Declared 36-byte main-executable ranges with the same complete instruction structure', matches=matches), indent=2) + '\n')
print(f'Guarded-bit census: {len(matches)} family members; {sum(not r["accepted"] for r in matches)} unaccepted.')
for row in matches:
    if not row['accepted']:
        print(json.dumps(row))
