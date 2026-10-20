"""Extend the latest cumulative gate for one independently probed curated batch.

Usage: prepare_fm_continuation_acceptance.py packet structure 0016c2b0
Preserves earlier gates and binds the new source, bundle, and acceptance helper.
"""
import json
from pathlib import Path
import re
import sys

root = Path(__file__).resolve().parents[2]
audit = root / 'tools/kh2-audit'
area = root / 'analysis/final-mix'
new, old, address_argument = sys.argv[1:4]
input_bundle = Path(sys.argv[4]).resolve() if len(sys.argv) > 4 else None
assert all(re.fullmatch('[a-z]+', value) for value in (new, old))
addresses = address_argument.split(',')
assert addresses and len(addresses) == len(set(addresses))
assert all(re.fullmatch('[0-9a-f]{8}', address) for address in addresses)
prior = json.loads((area / f'primary-{old}-checkpoint-2026-10-07.json').read_text())
source = area / f'recovery-experiments/fm_primary_{new}_recovered.cpp'
sources = json.loads(input_bundle.read_text()) if input_bundle else [source.relative_to(root).as_posix()]
if input_bundle:
    assert input_bundle.is_relative_to(root)
proved = set()
for relative in sources:
    candidate = root / relative
    assert candidate.is_relative_to(root)
    proof = json.loads(candidate.with_suffix('.verification.json').read_text())
    current = {r['address'] for r in proof['rows']}
    assert not proved.intersection(current)
    proved.update(current)
    assert all(r['exact_match'] for r in proof['rows'])
assert proved == set(addresses)
bundle = area / f'recovery-experiments/primary-{new}-curated-bundle.json'
gate = audit / f'verify_fm_primary_{new}_checkpoint.py'
assert not bundle.exists() and not gate.exists()
text = (audit / f'verify_fm_primary_{old}_checkpoint.py').read_text()
text, count = re.subn(r"prior = read\(analysis / 'primary-[a-z]+-checkpoint-2026-10-07.json'\)",
                     f"prior = read(analysis / 'primary-{old}-checkpoint-2026-10-07.json')", text)
assert count == 1
text, count = re.subn(r"assert prior\['active_exact_matches'\] == \d+",
                     f"assert prior['active_exact_matches'] == {prior['active_exact_matches']}", text)
assert count == 1
last = f"('primary-{old}-curated-bundle', "
text, count = re.subn(re.escape(last) + r"(\d+)\)\]",
                     lambda m: last + m[1] + f"), ('primary-{new}-curated-bundle', {len(addresses)})]", text)
assert count == 1
text = text.replace(f"if name == 'primary-{old}-curated-bundle':", f"if name == 'primary-{new}-curated-bundle':")
text, count = re.subn(r'assert selected == \{[^\n]+\}', 'assert selected == ' + repr(set(addresses)), text)
assert count == 1
text = text.replace(f"'verify_fm_primary_{old}_checkpoint.py'", f"'verify_fm_primary_{new}_checkpoint.py'")
text, count = re.subn(r"'prepare_fm_primary_[a-z]+_acceptance.py'", "'prepare_fm_continuation_acceptance.py'", text)
assert count == 1 or (count == 0 and "'prepare_fm_continuation_acceptance.py'" in text)
text = text.replace(f"'fm_primary_{old}', 'primary-{old}-'))",
                    f"'fm_primary_{old}', 'primary-{old}-', 'fm_primary_{new}', 'primary-{new}-'))")
text = text.replace(f"'primary-{old}-'))", f"'primary-{old}-', 'primary-{new}-'))")
text = text.replace(f"'session': '2026-10-07-primary-{old}'", f"'session': '2026-10-07-primary-{new}'")
text = text.replace(f"(analysis / 'primary-{old}-checkpoint-2026-10-07.json').write_text",
                    f"(analysis / 'primary-{new}-checkpoint-2026-10-07.json').write_text")
text = text.replace(f'Primary {old} checkpoint PASS:', f'Primary {new} checkpoint PASS:')
finish = audit / 'finish_fm_primary_matrix.py'
finish_text = finish.read_text()
finish_text = finish_text.replace(f"'primary-{old}')", f"'primary-{old}', 'primary-{new}')")
finish_text = finish_text.replace(f"if batch == 'primary-{old}':", f"if batch in ('primary-{old}', 'primary-{new}'):")
finish_text = finish_text.replace('for name in bundles:',
                                f"if batch == 'primary-{new}':\n    bundles.append('primary-{new}-curated-bundle')\nfor name in bundles:")
compile(text, str(gate), 'exec')
compile(finish_text, str(finish), 'exec')
bundle.write_text(json.dumps(sources, indent=2) + '\n')
gate.write_text(text, newline='\n')
finish.write_text(finish_text, newline='\n')
print(f'Prepared {new}: {len(addresses)} functions, prior {prior["active_exact_matches"]} exact matches.')
