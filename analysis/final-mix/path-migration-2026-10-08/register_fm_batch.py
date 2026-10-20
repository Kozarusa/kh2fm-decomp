"""Register a curated source batch only in nonoverlapping FM candidate ranges."""
import csv
import hashlib
import json
from pathlib import Path
import re
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/kh2-reference/tools'))
from common import resolve_symbol_name

ROOT = Path(__file__).resolve().parents[2]
reference = ROOT / 'tools/kh2-reference'
source = Path(sys.argv[1])
batch = sys.argv[2]
assert not source.is_absolute() and '..' not in source.parts
assert re.fullmatch(r'[a-z0-9-]+', batch)
expected_hash = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
original = (reference / 'SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest() == expected_hash
source_text = (reference / source).read_text()
range_proof = None
if '--range-proof' in sys.argv[3:]:
    assert '--include-declared' in sys.argv[3:]
    proof_path = Path(sys.argv[sys.argv.index('--range-proof') + 1]).resolve()
    assert proof_path.is_relative_to(ROOT)
    range_proof = json.loads(proof_path.read_text())
    assert range_proof['source_sha256'] == hashlib.sha256((reference / source).read_bytes()).hexdigest()
    proof_rows = {row['address']: row for row in range_proof['rows']}
    assert len(proof_rows) == len(range_proof['rows'])
definitions = re.findall(r'^\s*((?:[\w:*&]+\s+)+[*&]*func_([0-9a-f]{8})\([^;{}]*\))\s*\{', source_text, re.M)
addresses = [address for signature, address in definitions]
assert addresses and len(addresses) == len(set(addresses))
candidates = {r['address']: r for r in json.loads((ROOT / 'analysis/final-mix/native-pseudocode/additional-boundary-candidates.json').read_text())}
include_declared = '--include-declared' in sys.argv[3:]
compiled = {r['address'] for r in json.loads((ROOT / 'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
if include_declared:
    candidates.update({r['address']: r for r in (json.loads(line) for line in
        (ROOT / 'analysis/final-mix/native-pseudocode/main.jsonl').read_text().splitlines())})
layout_path = reference / 'layout.tsv'
registry_path = reference / 'functions.tsv'
layout_lines = layout_path.read_text().splitlines()
layout = list(csv.DictReader((line for line in layout_lines if not line.startswith('#')), delimiter='\t'))
entries = [line for line in layout_lines if not line.startswith('#') and not line.startswith('addr\t')]
selected = []
registry_rows = [line.split('\t') for line in registry_path.read_text().splitlines()
                 if line and not line.startswith('#')]
existing_symbols = {address.lower(): name for name, address in registry_rows}
assert len(existing_symbols) == len(registry_rows), 'Duplicate existing registry address'
declarations = []
for signature, address in definitions:
    if address in existing_symbols and existing_symbols[address] != f'func_{address}':
        declarations.append(signature + ' asm("' + resolve_symbol_name(existing_symbols[address]) + '");')
for address in addresses:
    candidate = candidates[address]
    start = int(address, 16)
    size = candidate['body_bytes']
    assert size > 0 and size % 4 == 0
    prior = next((row for row in layout if row['addr'] == address), None)
    if prior:
        assert include_declared and address not in compiled, address
        if range_proof is not None:
            proof = proof_rows[address]
            assert proof['exact_match'] and proof['compiled_size'] == proof['target_size']
            assert proof['compiled_hex'] == proof['target_hex']
            assert proof['target_size'] == int(prior['size'])
            offset = start - 0x100000 + 0x1000
            target = original[offset:offset + proof['target_size']]
            assert len(target) == proof['target_size']
            assert bytes.fromhex(proof['compiled_hex']) == target
            candidate = dict(candidate, body_bytes=proof['target_size'],
                             ghidra_body_bytes=size,
                             range_proof_sha256=hashlib.sha256(proof_path.read_bytes()).hexdigest())
            size = candidate['body_bytes']
        assert int(prior['size']) == size, 'Correct declared boundary before registration'
    assert not any(start < int(row['end'], 16) and start + size > int(row['addr'], 16)
                   for row in layout if row['addr'] != address), address
    selected.append(candidate)
    if not prior:
        entries.append(f'{address}\t{start+size:08x}\t{size}\tFUN_{address}')
manifest = [{'file': path.relative_to(reference).as_posix(), 'expected_stage_sha256': hashlib.sha256(path.read_bytes()).hexdigest()}
            for path in (registry_path, layout_path)]
manifest.append({'file': source.as_posix(), 'expected_stage_sha256': None})
out = ROOT / 'analysis/final-mix/native-build'
(out / f'{batch}-registration-evidence.json').write_text(json.dumps({
    'source': source.as_posix(),
    'source_sha256_before_aliases': hashlib.sha256((reference / source).read_bytes()).hexdigest(),
    'original_elf_sha256': expected_hash,
    'selected_ranges': selected,
    'range_proof': None if range_proof is None else {
        'file': proof_path.relative_to(ROOT).as_posix(),
        'sha256': hashlib.sha256(proof_path.read_bytes()).hexdigest(),
        'proof': range_proof,
    },
}, indent=2) + '\n')
(out / f'{batch}-sync-inputs.json').write_text(json.dumps(manifest, indent=2) + '\n')
layout_path.write_text('\n'.join([line for line in layout_lines if line.startswith('#') or line.startswith('addr\t')] + sorted(entries)) + '\n')
if declarations:
    (reference / source).write_text(source_text.replace('#include "../common/types.h"',
        '#include "../common/types.h"\n\n// Preserve original registry aliases.\n' + '\n'.join(declarations), 1))
with registry_path.open('a') as target:
    for row in selected:
        if row['address'] not in existing_symbols:
            target.write(f"func_{row['address']}\t{row['address']}\n")
print(f'Registered {len(selected)} FM candidate functions from {source}')
