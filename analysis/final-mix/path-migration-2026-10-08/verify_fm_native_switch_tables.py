"""Check full-link switch code/data without claiming original data was rebuilt."""
import hashlib
import json
from pathlib import Path
import struct
import sys

stage = Path('/root/kh2fm-build')
workspace = Path('/mnt/c/Users/KoZa/Documents/ChatGPT')
batch_name = sys.argv[1] if len(sys.argv) > 1 else 'switch-helpers'
batches = {
    'switch-helpers': ('fm_switch_helpers.cpp', [('0036ead0', '001e34e0', 88),
                                               ('0036eae4', '001e3538', 88)]),
    'switch-byte': ('fm_switch_byte.cpp', [('003739b0', '00272c20', 108)]),
}
source_name, table_specs = batches[batch_name]
linked_path = stage / 'out/linked.tmp.elf'
elf = linked_path.read_bytes()
original = (stage / 'SLPM_666.75').read_bytes()
expected = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
assert hashlib.sha256(original).hexdigest() == expected
assert (stage / 'kh2.elf').read_bytes() == original
header = struct.unpack_from('<16sHHIIIIIHHHHHH', elf)
assert header[0][:7] == b'\x7fELF\x01\x01\x01'
sections = [struct.unpack_from('<10I', elf, header[6] + i * header[11])
            for i in range(header[12])]
name_section = sections[header[13]]
names = elf[name_section[4]:name_section[4] + name_section[5]]
by_name = {names[s[0]:].split(b'\0', 1)[0].decode(): s for s in sections}
symbols = {}
for section in sections:
    if section[1] != 2:
        continue
    strings_section = sections[section[6]]
    strings = elf[strings_section[4]:strings_section[4] + strings_section[5]]
    assert section[9] == 16
    for offset in range(section[4], section[4] + section[5], 16):
        symbol = struct.unpack_from('<IIIBBH', elf, offset)
        name = strings[symbol[0]:].split(b'\0', 1)[0].decode()
        if name.startswith('fm_switch_table_') or name in {f'D_{a}' for a, _, _ in table_specs}:
            assert name not in symbols
            symbols[name] = symbol

data_section = by_name['.cxx_data']
data = elf[data_section[4]:data_section[4] + data_section[5]]
rows = []
for address, function, code_size in table_specs:
    symbol = symbols[f'D_{address}']
    assert symbol[1] == int(address, 16) and symbol[2] == 0
    assert symbol[5] == 0xfff1 and symbol[3] >> 4 == 1  # ABS, GLOBAL
    offset = int(address, 16) - 0x100000 + 0x1000
    table = original[offset:offset + 20]
    generated = symbols[f'fm_switch_table_{function}']
    assert generated[2] == 20 and sections[generated[5]] == data_section
    position = generated[1] - data_section[3]
    assert position >= 0 and data[position:position + 20] == table
    rows.append({'original_table_address': address, 'size': 20,
                 'linked_symbol_is_original_absolute_address': True,
                 'generated_data_address': f'{data_section[3] + position:08x}',
                 'generated_data_exact_match': True, 'hex': table.hex()})
proof_path = workspace / f'analysis/final-mix/native-build/{batch_name}-batch-verification.json'
batch = json.loads(proof_path.read_text())
sizes = {function: size for _, function, size in table_specs}
assert {row['address'] for row in batch} == set(sizes)
assert all(row['compiled_size'] == row['target_size'] == sizes[row['address']] and row['exact_match']
           for row in batch)
source = stage / 'src/anon' / source_name
assert source.read_bytes() == (workspace / 'tools/kh2-reference/src/anon' / source_name).read_bytes()
receipt = {'original_elf_sha256': expected,
           'linked_elf_sha256': hashlib.sha256(elf).hexdigest(),
           'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
           'batch_proof_sha256': hashlib.sha256(proof_path.read_bytes()).hexdigest(),
           'tables': rows,
           'limitations': ['Compiled tables match in the auxiliary linked data section.',
                           'Function references resolve to original absolute table addresses.',
                           'The rebuilt ELF retains original tables; data integration is not proved.',
                           'Runtime behavior and table immutability remain unverified.']}
(workspace / f'analysis/final-mix/native-build/{batch_name}-table-verification.json').write_text(
    json.dumps(receipt, indent=2) + '\n')
print(f'Full native switch proof {batch_name}: {len(batch)}/{len(batch)} code ranges, '
      f'{len(rows)}/{len(rows)} generated tables exact; original table references verified.')
