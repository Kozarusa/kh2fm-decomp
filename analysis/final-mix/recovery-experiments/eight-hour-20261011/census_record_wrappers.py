"""Recognize complete field-load tail wrappers without trusting pseudocode.

Only a narrow proven frame, pointer transport, scalar field loads, immediate
arguments, and one final tail transfer are permitted. Other operations reject
the range. This is candidate discovery, not acceptance or final ABI inference.
"""
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
load_types = {32: 's8', 33: 's16', 35: 's32', 36: 'u8', 37: 'u16', 49: 'f32'}
for boundary in load_boundaries(reference / 'layout.tsv'):
    if not 28 <= boundary.size <= 128 or boundary.size % 4:
        continue
    data = read_elf_vaddr(original, boundary.addr, boundary.size)
    words = struct.unpack('<' + 'I' * (len(data)//4), data)
    if words[0] != 0x27bdfff0 or words[-1] != 0x27bd0010 or words[-3] != 0xdfbf0000 or words[-2] >> 26 != 2:
        continue
    operations = []
    saved_pointer = False
    saved_ra = False
    input_overwritten = False
    int_args = {}
    float_args = {}
    valid = True
    for index, word in enumerate(words[1:-3], 1):
        if word == 0xffbf0000 and not saved_ra:
            saved_ra = True
            continue
        if word == 0x0080782d and not saved_pointer and not input_overwritten:
            saved_pointer = True
            continue
        op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        immediate = struct.unpack('<h', struct.pack('<H', word & 0xffff))[0]
        if op == 9 and rs == 0 and 4 <= rt <= 11 and rt not in int_args:
            item = dict(kind='constant', register=rt, type='s32', value=immediate, instruction_index=index)
            int_args[rt] = item
            operations.append(item)
            input_overwritten |= rt == 4
            continue
        if op not in load_types or rs not in [4, 15] or immediate < 0:
            valid = False
            break
        if rs == 15 and not saved_pointer or rs == 4 and input_overwritten:
            valid = False
            break
        if op == 49:
            if rt not in [12, 13] or rt in float_args:
                valid = False
                break
            item = dict(kind='field', register=rt, type='f32', offset=immediate, instruction_index=index)
            float_args[rt] = item
        else:
            if not 4 <= rt <= 11 or rt in int_args:
                valid = False
                break
            item = dict(kind='field', register=rt, type=load_types[op], offset=immediate, instruction_index=index)
            int_args[rt] = item
            input_overwritten |= rt == 4
        operations.append(item)
    if not valid or not saved_ra or not saved_pointer or not int_args:
        continue
    if sorted(int_args) != list(range(4, max(int_args)+1)):
        continue
    if float_args and sorted(float_args) != list(range(12, max(float_args)+1)):
        continue
    address = f'{boundary.addr:08x}'
    target = ((boundary.addr + boundary.size - 4) & 0xf0000000) | ((words[-2] & 0x03ffffff) << 2)
    matches.append(dict(address=address, bytes=boundary.size, accepted=address in accepted,
                        state=states.get(address), callee=f'{target:08x}',
                        operations=operations, integer_arguments=sorted(int_args), floating_arguments=sorted(float_args),
                        original_range_sha256=hashlib.sha256(data).hexdigest()))
assert any(r['address'] == '00174af8' for r in matches), 'Proven positive control missing'
path = base / 'record-wrapper-census.json'
assert not path.exists()
path.write_text(json.dumps(dict(positive_control='00174af8', scope='Declared main-executable ranges with the narrow proven wrapper frame',
                                limitations=['Prototype and source-type inference remain provisional.', 'Every candidate needs original range proof, independent recompilation and full acceptance.'], matches=matches), indent=2) + '\n')
print(f'Record-wrapper census: {len(matches)} recognized; {sum(not r["accepted"] for r in matches)} unaccepted.')
for row in matches:
    if not row['accepted']:
        print(f'{row["address"]}: {row["bytes"]} bytes; {row["state"]}; callee {row["callee"]}; {len(row["operations"])} argument transports')
