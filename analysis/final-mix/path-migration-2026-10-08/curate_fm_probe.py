"""Copy only complete exact definitions from a hash-bound isolated probe."""
import hashlib
import json
from pathlib import Path
import re
import sys

root = Path(__file__).resolve().parents[2]
source = Path(sys.argv[1]).resolve()
target = Path(sys.argv[2]).resolve()
assert source.is_relative_to(root) and target.is_relative_to(root)
assert not target.exists(), 'Refuse to overwrite a prior curated source'
text = source.read_text()
proof = json.loads(source.with_suffix('.verification.json').read_text())
assert proof['source_sha256'] == hashlib.sha256(source.read_bytes()).hexdigest()
exclusions = set()
exclusion_receipt = None
if len(sys.argv) > 3:
    exclusion_path = Path(sys.argv[3]).resolve()
    assert exclusion_path.is_relative_to(root)
    values = json.loads(exclusion_path.read_text())
    assert isinstance(values, list) and all(re.fullmatch('[0-9a-f]{8}', value) for value in values)
    exclusions = set(values)
    exclusion_receipt = {'file': exclusion_path.relative_to(root).as_posix(),
                         'sha256': hashlib.sha256(exclusion_path.read_bytes()).hexdigest()}
original = (root / 'tools/kh2-reference/SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest() == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
accepted = {}
for row in proof['rows']:
    if not row['exact_match'] or row['address'] in exclusions:
        continue
    assert row['compiled_size'] == row['target_size']
    assert row['compiled_hex'] == row['target_hex']
    offset = int(row['address'], 16) - 0x100000 + 0x1000
    assert bytes.fromhex(row['compiled_hex']) == original[offset:offset + row['target_size']]
    assert row['address'] not in accepted
    accepted[row['address']] = row
assert accepted
pattern = r'^\s*(?:[\w:*&]+\s+)+[*&]*func_([0-9a-f]{8})\([^;{}]*\)\s*\{'
definitions = list(re.finditer(pattern, text, re.M))
assert definitions
# Blank lexical strings/comments without changing offsets before counting braces.
lexical = re.sub(r'"(?:\\.|[^"\\])*"|\x27(?:\\.|[^\x27\\])*\x27|//[^\n]*|/\*.*?\*/',
                 lambda match: ' ' * len(match.group()), text, flags=re.S)
pieces = [text[:definitions[0].start()].rstrip()]
selected = []
for match in definitions:
    address = match.group(1)
    if address not in accepted:
        continue
    start = match.end() - 1
    depth = 1
    end = start + 1
    while depth:
        assert end < len(lexical), 'Unclosed definition'
        depth += (lexical[end] == '{') - (lexical[end] == '}')
        end += 1
    pieces.append(text[match.start():end].strip())
    selected.append(address)
assert set(selected) == set(accepted)
target.write_text('\n\n'.join(pieces) + '\n')
receipt = {'probe_source': source.relative_to(root).as_posix(),
           'probe_source_sha256': proof['source_sha256'],
           'probe_proof_sha256': hashlib.sha256(source.with_suffix('.verification.json').read_bytes()).hexdigest(),
           'curated_source': target.relative_to(root).as_posix(),
           'curated_source_sha256': hashlib.sha256(target.read_bytes()).hexdigest(),
           'selected_addresses': selected,
           'exclusion_receipt': exclusion_receipt,
           'limitations': ['Curated source still requires a new probe, registration and full build.']}
target.with_suffix('.curation.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(f'Curated {len(selected)} exact definitions; new source remains isolated.')
