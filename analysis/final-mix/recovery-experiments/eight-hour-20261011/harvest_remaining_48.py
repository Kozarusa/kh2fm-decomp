from pathlib import Path
import hashlib
import json
import sqlite3
import subprocess
import sys
base = Path(__file__).resolve().parent
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
leases = json.loads((base / 'remaining-48-leases.json').read_text())
db_path = base.parents[1] / 'worker-coordination/recovery-queue.sqlite3'
db = sqlite3.connect(db_path.as_uri() + '?mode=ro', uri=True)
states = dict(db.execute('select address,state from targets'))
proofs = []
for path in base.glob('eight_hour_*.verification.json'):
    source = path.with_suffix('').with_suffix('.cpp')
    proof = json.loads(path.read_text())
    if len(proof['rows']) == 1 and proof['rows'][0]['exact_match']:
        assert hashlib.sha256(source.read_bytes()).hexdigest() == proof['source_sha256']
        proofs.append((proof['rows'][0]['address'], source, path))
for lease in leases:
    address = lease['address']
    if states[address] != 'leased':
        continue
    exact = [(s,p) for a,s,p in proofs if a==address]
    if exact:
        source, proof = min(exact, key=lambda row: (row[0].read_text().count('asm'), len(row[0].read_text()), row[0].name))
        command = [sys.executable, str(helper), 'submit', '--address', address, '--token', lease['token'], '--source', str(source), '--proof', str(proof)]
    else:
        command = [sys.executable, str(helper), 'heartbeat', '--address', address, '--token', lease['token']]
    result = subprocess.run(command, text=True, capture_output=True)
    assert result.returncode == 0, result.stdout + result.stderr
    print(('Submitted exact ' if exact else 'Renewed unresolved ') + address)
