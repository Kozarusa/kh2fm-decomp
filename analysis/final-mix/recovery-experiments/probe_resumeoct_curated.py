from pathlib import Path
import json, subprocess
workspace=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
audit=workspace.parent/'Public/tools/kh2-audit'
inputs=json.loads((workspace/'analysis/final-mix/recovery-experiments/primary-resumeoct-curated-inputs.json').read_text())
for relative in inputs:
 source=workspace/relative
 with source.with_suffix('.probe.log').open('w') as log:
  subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT,check=True)
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 assert all(r['exact_match'] and r['compiled_size']==r['target_size'] for r in proof['rows'])
 print(source.name+': complete exact',flush=True)
