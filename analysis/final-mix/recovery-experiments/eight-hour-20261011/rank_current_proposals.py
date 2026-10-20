"""Read-only ranking against current accepted ranges and original ELF bytes."""
import hashlib
import json
from pathlib import Path
import sqlite3
import sys

base = Path(__file__).resolve().parent
workspace = base.parents[3]
area = workspace / 'analysis/final-mix'
reference = workspace.parent / 'Public/tools/kh2-reference'
sys.path.insert(0, str(reference / 'tools'))
from common import load_elf_image, read_elf_vaddr, load_boundaries

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

accepted = {r['address'] for r in json.loads((area / 'native-build/compiler-range-verification.json').read_text())}
original = load_elf_image(reference / 'SLPM_666.75')
assert hashlib.sha256(original[0]).hexdigest() == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
boundaries = {f'{r.addr:08x}': r.size for r in load_boundaries(reference / 'layout.tsv')}
db = sqlite3.connect('file:' + str(area / 'worker-coordination/recovery-queue.sqlite3') + '?mode=ro', uri=True)
states = {a: (state, queue) for a, state, queue in db.execute('select address,state,queue from targets')}
db.close()
best = {}
scanned = 0
skipped = []
for path in (area / 'recovery-experiments').rglob('*.verification.json'):
    source = path.with_suffix('').with_suffix('.cpp')
    if not source.exists():
        continue
    proof = json.loads(path.read_text())
    if 'source_sha256' not in proof or not isinstance(proof.get('rows'), list):
        continue
    candidates = [r for r in proof['rows'] if r.get('address') not in accepted and r.get('compiled_size') == r.get('target_size') and 'compiled_hex' in r]
    if not candidates:
        continue
    scanned += 1
    if digest(source) != proof['source_sha256']:
        skipped.append(dict(proof=str(path), reason='Source hash changed; cannot reuse proof'))
        continue
    for row in candidates:
        address = row['address']
        if address not in boundaries or boundaries[address] != row['target_size']:
            continue
        a = bytes.fromhex(row['target_hex'])
        b = bytes.fromhex(row['compiled_hex'])
        if len(a) != row['target_size'] or len(b) != len(a):
            continue
        if a != read_elf_vaddr(original, int(address, 16), len(a)):
            skipped.append(dict(proof=str(path), address=address, reason='Target differs from original range'))
            continue
        differences = sum(a[i:i+4] != b[i:i+4] for i in range(0, len(a), 4))
        item = dict(address=address, bytes=len(a), different_words=differences,
                    source=str(source), source_sha256=proof['source_sha256'],
                    proof=str(path), proof_sha256=digest(path), state=states.get(address))
        if address not in best or (differences, str(source)) < (best[address]['different_words'], best[address]['source']):
            best[address] = item
    if scanned % 500 == 0:
        print(f'Checked {scanned} candidate-bearing proofs; {len(best)} unresolved ranges ranked', flush=True)
ranked = sorted(best.values(), key=lambda r: (r['different_words'], r['bytes'], r['address']))
output = base / 'current-ranked-proposals.json'
assert not output.exists()
output.write_text(json.dumps(dict(accepted_ranges_excluded=len(accepted), candidate_proofs_scanned=scanned,
                                  ranked=ranked, rejected_proofs=skipped), indent=2) + '\n')
for row in ranked[:20]:
    print(f'{row["address"]}: {row["different_words"]} differing words, {row["bytes"]} bytes; {row["state"]}; {Path(row["source"]).name}')
print(f'Ranked {len(ranked)} unresolved ranges; excluded {len(skipped)} invalid/stale proofs.')
