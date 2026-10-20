"""Verify the two isolated switch probes and their compiler-generated tables."""
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
out = ROOT / 'analysis/final-mix/recovery-experiments'
source = out / 'fm_switch_helpers.cpp'
linked = out / 'fm_switch_helpers.probe.elf'
original_path = ROOT / 'tools/kh2-reference/SLPM_666.75'
original = original_path.read_bytes()
original_hash = hashlib.sha256(original).hexdigest()
assert original_hash == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
proof_path = out / 'fm_switch_helpers.verification.json'
proof = json.loads(proof_path.read_text())
assert proof['source_sha256'] == hashlib.sha256(source.read_bytes()).hexdigest()
assert {row['address'] for row in proof['rows']} == {'001e34e0', '001e3538'}
for row in proof['rows']:
    assert row['compiled_size'] == row['target_size'] == 88
    assert row['exact_match'] and row['compiled_hex'] == row['target_hex']
    offset = int(row['address'], 16) - 0x100000 + 0x1000
    assert bytes.fromhex(row['target_hex']) == original[offset:offset + 88]

elf = linked.read_bytes()
assert elf[:7] == b'\x7fELF\x01\x01\x01'
header = struct.unpack_from('<16sHHIIIIIHHHHHH', elf)
sections = [struct.unpack_from('<10I', elf, header[6] + i * header[11])
            for i in range(header[12])]
names_section = sections[header[13]]
names = elf[names_section[4]:names_section[4] + names_section[5]]
by_name = {names[s[0]:].split(b'\0', 1)[0].decode(): s for s in sections}
for row in proof['rows']:
    section = by_name[f'.s_{row["address"]}']
    assert section[3] == int(row['address'], 16) and section[5] == 88
    assert elf[section[4]:section[4] + 88] == bytes.fromhex(row['compiled_hex'])
rows = []
for address, function in (('0036ead0', '001e34e0'), ('0036eae4', '001e3538')):
    section = by_name[f'.data.fm_switch_table_{function}']
    assert section[5] == 24
    assert elf[section[4] + 20:section[4] + 24] == bytes(4)
    compiled = elf[section[4]:section[4] + 20]
    offset = int(address, 16) - 0x100000 + 0x1000
    target = original[offset:offset + 20]
    assert compiled == target, address
    rows.append({'address': address, 'size': 20, 'section_zero_padding': 4, 'exact_match': True,
                 'compiled_hex': compiled.hex(), 'original_hex': target.hex(),
                 'targets': [f'{value:08x}' for value in struct.unpack('<5I', target)]})
receipt = {
    'status': 'isolated_compiler_proof_only',
    'original_elf_sha256': original_hash,
    'inputs': {str(p.relative_to(ROOT)).replace('\\', '/'): hashlib.sha256(p.read_bytes()).hexdigest()
               for p in (source, linked, out / 'fm_switch_helpers.probe.o', proof_path)},
    'code_matches': 2, 'table_matches': 2, 'tables': rows,
    'limitations': ['Ghidra body sizes remain 52 bytes; ledger ranges are 88 bytes.',
                    'This receipt does not verify registration or full build input provenance.',
                    'Runtime behavior and table immutability are not proved.'],
}
(out / 'fm_switch_helpers.table-verification.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('Isolated switch proof: 2/2 full code ranges, 2/2 generated tables exact.')
