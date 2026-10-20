from pathlib import Path
import subprocess,json
w=Path('/mnt/c/Users/KoZa/Documents/AGENTS')
base=w/'Codex/analysis/final-mix/recovery-experiments/queue-run-20261009/primary'
for name in ['fm_queue_primary_00163828_968096b4_classify_compare.cpp','fm_queue_primary_00153540_c5ea05d3_color_words.cpp']:
 source=base/name
 with source.with_suffix('.probe.log').open('x') as log:
  completed=subprocess.run(['python3',str(w/'Public/tools/kh2-audit/probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if completed.returncode:
  print(name,'probe failed; diagnostics saved',flush=True); continue
 for row in json.loads(source.with_suffix('.verification.json').read_text())['rows']:
  print(row['address'],row['compiled_size'],row['target_size'],row['exact_match'],flush=True)
