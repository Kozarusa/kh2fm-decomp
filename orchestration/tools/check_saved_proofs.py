"""Read-only recount of all saved WP proofs against their source and original ELF."""
import hashlib
import json
from pathlib import Path
import sys

root = Path('C:/Users/KoZa/Documents/AGENTS')
original = (root / 'Public/tools/kh2-reference/SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest() == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
for name in sys.argv[1:]:
    wp = root / 'Codex/analysis/final-mix/recovery-experiments/orch-shift1' / name
    total = 0
    for path in sorted(wp.glob('*.verification.json')):
        data = json.loads(path.read_text(encoding='utf-8'))
        source = Path(str(path).replace('.verification.json', '.cpp'))
        assert hashlib.sha256(source.read_bytes()).hexdigest() == data['source_sha256'], source
        assert len(data['rows']) == 1, path
        row = data['rows'][0]
        target = bytes.fromhex(row['target_hex'])
        compiled = bytes.fromhex(row['compiled_hex'])
        offset = int(row['address'], 16) - 0x100000 + 0x1000
        assert target == original[offset:offset + row['target_size']], path
        assert len(target) == row['target_size'] and len(compiled) == row['compiled_size'], path
        words = sum(target[i:i+4] != compiled[i:i+4] for i in range(0,max(len(target),len(compiled)),4))
        assert row['exact_match'] == (target == compiled), path
        print(f'{name} {source.stem}: {words} words, {len(compiled)}/{len(target)} bytes')
        total += 1
    print(f'{name}: {total} saved proofs checked; all hashes, sizes and original ELF slices agree.')
