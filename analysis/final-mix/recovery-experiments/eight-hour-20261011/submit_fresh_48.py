from pathlib import Path
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
leases = json.loads((base / 'fresh-48-leases.json').read_text())
variants = json.loads((base / 'fresh-48-variants.json').read_text()) + json.loads((base / 'id-predicate-v2-variants.json').read_text())
selected = []
for lease in leases:
    address = lease['address']
    exact = []
    for name in variants:
        if name.split('_')[2] != address:
            continue
        proof_path = (base / name).with_suffix('.verification.json')
        proof = json.loads(proof_path.read_text())
        if len(proof['rows']) == 1 and proof['rows'][0]['exact_match']:
            exact.append(name)
    assert exact, address
    # Prefer the earliest non-assembly exact proposal; preserve all alternatives.
    name = exact[0]
    source = base / name
    proof_path = source.with_suffix('.verification.json')
    result = subprocess.run([sys.executable, str(helper), 'submit', '--address', address, '--token', lease['token'], '--source', str(source), '--proof', str(proof_path)], text=True, capture_output=True)
    with (base / f'fresh48-submit-{address}.log').open('x') as stream:
        stream.write(result.stdout + result.stderr)
    assert result.returncode == 0, address
    selected.append({'address': address, 'source': name, 'proof': proof_path.name})
    print('Submitted exact ' + address)
with (base / 'fresh-48-selected.json').open('x') as stream:
    json.dump(selected, stream, indent=2)
