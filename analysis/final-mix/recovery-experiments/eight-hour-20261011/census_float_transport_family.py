"""Find complete declared ranges sharing the newly proven wrapper structure."""
import hashlib
import json
from pathlib import Path
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
control_proof = json.loads((base / 'eight_hour_00174af8_v3_pointer_dependencies_0.verification.json').read_text())['rows'][0]
assert control_proof['exact_match'] and control_proof['target_hex'] == control_proof['compiled_hex']
control = struct.unpack('<12I', bytes.fromhex(control_proof['target_hex']))
accepted = {r['address'] for r in json.loads((area / 'native-build/compiler-range-verification.json').read_text())}
variable = {3, 4, 5, 6, 7, 8, 10}
matches = []
for boundary in load_boundaries(reference / 'layout.tsv'):
    if boundary.size != 48:
        continue
    data = read_elf_vaddr(original, boundary.addr, boundary.size)
    words = struct.unpack('<12I', data)
    if not all((words[i] & 0xffff0000) == (control[i] & 0xffff0000) if i in variable and i != 10 else
               (words[i] & 0xfc000000) == (control[i] & 0xfc000000) if i == 10 else words[i] == control[i]
               for i in range(12)):
        continue
    address = f'{boundary.addr:08x}'
    target = ((boundary.addr + 44) & 0xf0000000) | ((words[10] & 0x03ffffff) << 2)
    matches.append(dict(address=address, accepted=address in accepted, callee=f'{target:08x}',
                        mode=words[3] & 0xffff,
                        load_offsets=[words[i] & 0xffff for i in [4, 5, 6, 7, 8]],
                        original_range_sha256=hashlib.sha256(data).hexdigest()))
assert any(r['address'] == '00174af8' for r in matches), 'Positive control missing'
output = base / 'float-transport-family-census.json'
assert not output.exists()
output.write_text(json.dumps(dict(positive_control='00174af8', declared_range_bytes=48,
                                 scope='Current declared 48-byte main-executable ranges only', matches=matches), indent=2) + '\n')
print(f'Positive-control census: {len(matches)} family members; {sum(not r["accepted"] for r in matches)} unaccepted.')
for row in matches:
    if not row['accepted']:
        print(json.dumps(row))
