"""Validate FM native export ledgers without claiming instruction equivalence."""
import collections
import csv
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / 'analysis/final-mix'
NATIVE = OUT / 'native-pseudocode'
inputs = json.loads((OUT / 'native-inputs.json').read_text())
records, modules, repairs, warnings = [], [], [], []
paths = [NATIVE / 'main.jsonl', *sorted((NATIVE / 'iop').glob('*/main.jsonl')),
         NATIVE / 'overlays/main.jsonl']
overlay_layout = {x['module']: x for x in json.loads((OUT / 'overlay-layout.json').read_text())}
for path in paths:
    rows = [json.loads(line) for line in path.read_text(encoding='utf-8').splitlines()]
    summary = json.loads(path.with_name('summary.json').read_text())
    assert summary['exported_function_count'] == len(rows)
    expected = inputs['SLPM_666.75']['sha256']
    if path.parent.parent.name == 'iop':
        source = next(x for key, x in inputs.items() if Path(key).name == path.parent.name)
        expected = source['sha256']
        assert summary['language'] == 'MIPS:LE:32:default'
    else:
        assert summary['language'] == 'r5900:LE:32:default'
    assert summary['executable_sha256'] == expected
    assert len({(row['module'], row['address']) for row in rows}) == len(rows)
    for row in rows:
        row['export_file'] = path.relative_to(ROOT).as_posix()
        if row['module'] in overlay_layout:
            layout = overlay_layout[row['module']]
            address = int(row['address'].rsplit(':', 1)[-1], 16)
            base = int(layout['candidate_base_address'], 16)
            assert base <= address < base + layout['payload_size']
        if row['status'] != 'unverified_pseudocode':
            repairs.append(row)
        # Runtime diagnostic string literals are not Ghidra analysis warnings.
        if re.search(r'/\* WARNING:', row.get('code') or '') or row.get('decompiler_message'):
            warnings.append({key: row[key] for key in ('module', 'address', 'status', 'export_file', 'decompiler_message')})
    records.extend(rows)
    modules.append({**summary, 'export_file': path.relative_to(ROOT).as_posix(),
                    'export_sha256': hashlib.sha256(path.read_bytes()).hexdigest()})

expected_iop = {Path(key).name for key in inputs if key.endswith('.IRX')}
assert {path.parent.name for path in paths if path.parent.parent.name == 'iop'} == expected_iop
assert {row['module'] for row in records if row['module'].endswith('.x')} == set(overlay_layout)
assert len({(row['module'], row['address']) for row in records}) == len(records)

with (ROOT / 'tools/kh2-reference/layout.tsv').open() as source:
    layout_rows = list(csv.DictReader((line for line in source if not line.startswith('#')), delimiter='\t'))
declared = {int(row['addr'], 16) for row in layout_rows}
observed = {int(row['address'], 16) for row in records if row['module'] == 'SLPM_666.75'}
comparison = {'declared_main_ranges': len(declared), 'range_ledger': 'tools/kh2-reference/layout.tsv',
              'range_ledger_contains_local_corrections': True,
              'observed_main_function_starts': len(observed),
              'shared_starts': len(declared & observed),
              'declared_only': [f'{x:08x}' for x in sorted(declared - observed)],
              'observed_only': [f'{x:08x}' for x in sorted(observed - declared)],
              'limitations': ['Agreement on starts does not prove correct function ends or source equivalence.']}
additional = [row for row in records if row['module'] == 'SLPM_666.75'
              and int(row['address'], 16) not in declared]
summary = {'function_candidates_by_module': dict(collections.Counter(row['module'] for row in records)),
           'total_function_candidates': len(records),
           'status_counts': dict(collections.Counter(row['status'] for row in records)),
           'functions_with_warning_or_message': len(warnings),
           'verified_matching_functions': None,
           'limitations': ['All exports are unverified pseudocode, including completed decompiler results.',
                          'Ghidra applies IRX relocations; project addresses are not verified runtime load addresses.',
                          'Overlay mappings derive from the FM ELF and trampoline targets, with runtime confirmation pending.',
                          'VU sections are excluded from these exports.']}
build_verification = OUT / 'native-build/native-build-verification.json'
if build_verification.exists():
    summary['main_cpp_build_checkpoint'] = json.loads(build_verification.read_text())
for name, value in [('summary.json', summary), ('module-exports.json', modules),
                    ('repair-queue.json', repairs), ('warning-queue.json', warnings),
                    ('additional-boundary-candidates.json', additional),
                    ('function-boundary-comparison.json', comparison)]:
    # Keep the main exporter summary in place; use a distinct combined ledger name.
    if name == 'summary.json': name = 'combined-summary.json'
    (NATIVE / name).write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
print(json.dumps(summary, indent=2))
