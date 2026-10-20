"""Verify the metadata repair and exact one-row decompiler export change."""
import hashlib
import json
from pathlib import Path

root = Path(__file__).resolve().parents[2]
native = root / 'analysis/final-mix/native-pseudocode'
receipt = json.loads((native / 'callback-flow-merge-v2.json').read_text())
prior = receipt['previous_receipt']
assert hashlib.sha256((root / prior['file']).read_bytes()).hexdigest() == prior['sha256']
for row in receipt['files']:
    assert hashlib.sha256((root / row['file']).read_bytes()).hexdigest() == row['sha256'], row['file']
before = (native / 'callback-flow-main-before-v1.jsonl').read_bytes()
after = (native / 'main.jsonl').read_bytes()
assert hashlib.sha256(before).hexdigest() == receipt['previous_main_sha256']
assert hashlib.sha256(after).hexdigest() == receipt['merged_main_sha256']
old_lines, new_lines = before.splitlines(keepends=True), after.splitlines(keepends=True)
assert len(old_lines) == len(new_lines)
changed = []
for old, new in zip(old_lines, new_lines):
    if old == new:
        continue
    old_row, new_row = json.loads(old), json.loads(new)
    assert old_row['address'] == new_row['address'] == '00315458'
    assert new_row == receipt['merged_rows']['00315458']
    assert {key: value for key, value in old_row.items() if key != 'code'} == {
        key: value for key, value in new_row.items() if key != 'code'}
    changed.append(new_row['address'])
assert changed == receipt['changed_export_addresses'] == ['00315458']
assert not receipt['executable_bytes_changed'] and not receipt['function_boundaries_changed']
assert receipt['flow_change'] == {
    'address': '00315460', 'previous': 'CALL_RETURN', 'current': 'NONE',
    'fallthrough': '00315468', 'direct_termination_override': 'CALL_RETURN'}
final = (native / 'callback-flow-export-final-v1/main.jsonl').read_bytes()
reopened = (native / 'callback-flow-export-reopened-v1/main.jsonl').read_bytes()
assert final == reopened
print('Callback flow PASS: saved/reopened export agrees; one code field changed, all other rows unchanged.')
