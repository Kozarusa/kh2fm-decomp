from pathlib import Path
import subprocess,json
w=Path('/mnt/c/Users/KoZa/Documents/AGENTS')
base=w/'Codex/analysis/final-mix/recovery-experiments/queue-run-20261009/primary'
for name in ['fm_queue_primary_002f3d08_4846aa31_matrix.cpp','fm_queue_primary_00178cf8_5292b726_zero.cpp']:
 source=base/name
 with source.with_suffix('.probe.log').open('x') as log:
  completed=subprocess.run(['python3',str(w/'Public/tools/kh2-audit/probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if completed.returncode:
  print(name,'probe failed; diagnostics saved',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 for row in proof['rows']:
  print(row['address'],row['compiled_size'],row['target_size'],row['exact_match'],flush=True)
