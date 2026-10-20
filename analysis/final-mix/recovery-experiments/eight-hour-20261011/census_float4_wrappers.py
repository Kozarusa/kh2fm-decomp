"""Find complete four-float record wrappers using the proven 36-byte frame."""
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
proof = json.loads((base / 'eight_hour_002e7b88_float4.verification.json').read_text())['rows'][0]
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
    w = struct.unpack('<9I', data)
    if not all((w[i] & 0xffff0000) == (control[i] & 0xffff0000) if i in [1, 3, 4, 5] else
               w[i] >> 26 == 2 if i == 7 else w[i] == control[i] for i in range(9)):
        continue
    address = f'{boundary.addr:08x}'
    callee = ((boundary.addr + 32) & 0xf0000000) | ((w[7] & 0x03ffffff) << 2)
    offsets = [struct.unpack('<h', struct.pack('<H', w[i] & 0xffff))[0] for i in [3, 4, 5, 1]]
    matches.append(dict(address=address, offsets=offsets, callee=f'{callee:08x}', accepted=address in accepted,
                        state=states.get(address), original_range_sha256=hashlib.sha256(data).hexdigest()))
assert any(r['address'] == '002e7b88' for r in matches), 'Positive control missing'
path = base / 'float4-wrapper-census.json'
assert not path.exists()
path.write_text(json.dumps(dict(positive_control='002e7b88', scope='Declared complete 36-byte four-float tail wrappers', matches=matches), indent=2) + '\n')
print(f'Four-float wrapper census: {len(matches)} members; {sum(not r["accepted"] for r in matches)} unaccepted.')
for row in matches:
    if not row['accepted']:
        print(json.dumps(row))
