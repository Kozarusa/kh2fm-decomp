"""Read-only census of complete 40-byte virtual-forwarding instruction families."""
from pathlib import Path
import json
import hashlib
import sqlite3
import struct
import sys
base = Path(__file__).resolve().parent
workspace = base.parents[3]
reference = workspace.parent / 'Public/tools/kh2-reference'
sys.path.insert(0, str(reference / 'tools'))
from common import load_elf_image, read_elf_vaddr, load_boundaries
image = load_elf_image(reference / 'SLPM_666.75')
assert hashlib.sha256(image[0]).hexdigest() == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
accepted = {row['address'] for row in json.loads((workspace / 'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
db_path = workspace / 'analysis/final-mix/worker-coordination/recovery-queue.sqlite3'
db = sqlite3.connect(db_path.as_uri() + '?mode=ro', uri=True)
states = {a: (state, queue) for a, state, queue in db.execute('select address,state,queue from targets')}
pattern = [0x27bdfff0, 0xffbf0000, None, None, None, None, 0, 0xdfbf0000, 0x03e00008, 0x27bd0010]
matches = []
for boundary in load_boundaries(reference / 'layout.tsv'):
    if boundary.size != 40:
        continue
    code = read_elf_vaddr(image, boundary.addr, 40)
    words = struct.unpack('<10I', code)
    if any(expected is not None and actual != expected for actual, expected in zip(words, pattern)):
        continue
    # Require the three loads and indirect call to follow the recovered owner/object/table chain.
    if words[2] >> 16 != 0x8c84 or words[3] >> 16 != 0x8c8e or words[3] & 0xffff != 0:
        continue
    if words[4] >> 16 != 0x8dcf or words[5] != 0x01e0f809:
        continue
    address = f'{boundary.addr:08x}'
    owner_offset = struct.unpack('<h', code[8:10])[0]
    method_offset = struct.unpack('<h', code[16:18])[0]
    matches.append({'address': address, 'owner_offset': owner_offset, 'method_offset': method_offset,
                    'accepted': address in accepted, 'queue_state': states.get(address),
                    'target_sha256': hashlib.sha256(code).hexdigest()})
output = base / 'virtual-forwarder-census.json'
assert not output.exists()
output.write_text(json.dumps(matches, indent=2) + '\n')
print(json.dumps(matches, indent=2))
