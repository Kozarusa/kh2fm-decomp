from pathlib import Path
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
addresses = sorted({name.split('_')[2] for name in json.loads((base / 'remaining-48-variants.json').read_text())})
leases = []
for address in addresses:
    result = subprocess.run([sys.executable, str(helper), 'claim', '--worker', 'eight-hour-primary', '--count', '1', '--address', address], text=True, capture_output=True)
    with (base / f'remaining48-claim-{address}.log').open('x') as stream:
        stream.write(result.stdout + result.stderr)
    assert result.returncode == 0, address
    rows = json.loads(result.stdout)['leases']
    assert len(rows) == 1 and rows[0]['address'] == address, address
    leases.extend(rows)
    print('Claimed ' + address)
with (base / 'remaining-48-leases.json').open('x') as stream:
    json.dump(leases, stream, indent=2)
record_path = base.parents[1] / 'worker-coordination/eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
if not any(row['phase'] == 'queuepsi' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase': 'queuepsi', 'functions': 8, 'instruction_bytes': 384, 'exact_total': 5876, 'checkpoint': 'primary-queuepsi-checkpoint-2026-10-08.json'})
record['phase'] = 'fresh-48-byte-function-recovery'
record_path.write_text(json.dumps(record, indent=2) + '\n')
