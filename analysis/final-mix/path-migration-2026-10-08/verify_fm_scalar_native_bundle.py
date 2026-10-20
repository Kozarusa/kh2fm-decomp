"""Bind a curated scalar bundle to full-build records and staged source hashes."""
import hashlib
import json
from pathlib import Path
import sys

stage = Path('/root/kh2fm-build')
workspace = Path('/mnt/c/Users/KoZa/Documents/ChatGPT')
inputs = Path(sys.argv[1]).resolve()
assert inputs.is_relative_to(workspace)
records_path = stage / 'out/compiler-range-verification.json'
records = json.loads(records_path.read_text())
by_address = {row['address']: row for row in records}
assert len(by_address) == len(records)
groups = []
selected = set()
for relative in json.loads(inputs.read_text()):
    probe_source = (workspace / relative).resolve()
    assert probe_source.is_relative_to(workspace)
    proof_path = probe_source.with_suffix('.verification.json')
    proof = json.loads(proof_path.read_text())
    assert proof['source_sha256'] == hashlib.sha256(probe_source.read_bytes()).hexdigest()
    assert all(row['exact_match'] for row in proof['rows'])
    source_relative = f'src/anon/{probe_source.name}'
    source = stage / source_relative
    assert source.read_bytes() == (workspace / 'tools/kh2-reference' / source_relative).read_bytes()
    addresses = {row['address'] for row in proof['rows']}
    assert len(addresses) == len(proof['rows']) and not addresses & selected
    assert addresses == {row['address'] for row in records if row['source'] == source_relative}
    for row in proof['rows']:
        built = by_address[row['address']]
        assert built['source'] == source_relative
        assert built['unmodified_compiled_symbol_match'] and built['size_status'] == 'equal_size'
        assert built['compiled_symbol_size'] == built['declared_range_size'] == row['target_size']
    selected.update(addresses)
    groups.append({'source': source_relative, 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
                   'probe_proof_sha256': hashlib.sha256(proof_path.read_bytes()).hexdigest(),
                   'exact_functions': len(addresses), 'addresses': sorted(addresses)})
receipt = {'bundle': inputs.relative_to(workspace).as_posix(),
           'bundle_sha256': hashlib.sha256(inputs.read_bytes()).hexdigest(),
           'compiler_records_sha256': hashlib.sha256(records_path.read_bytes()).hexdigest(),
           'linked_elf_sha256': hashlib.sha256((stage / 'out/linked.tmp.elf').read_bytes()).hexdigest(),
           'exact_functions': len(selected), 'groups': groups,
           'limitations': ['Callee prototypes and source types remain provisional.',
                           'Equal original instructions do not prove runtime behavior or all boundaries.']}
output = workspace / f'analysis/final-mix/native-build/{inputs.stem}-verification.json'
output.write_text(json.dumps(receipt, indent=2) + '\n')
print(f'Native scalar bundle PASS: {len(selected)} exact functions across {len(groups)} source files.')
