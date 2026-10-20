from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_shortfamily_v2_001ac700_1.cpp', 'fm_primary_shortfamily_v2_001ac700_2.cpp', 'fm_primary_shortfamily_v2_0028ac98_1.cpp', 'fm_primary_shortfamily_v2_0028ac98_2.cpp', 'fm_primary_shortfamily_v2_00195c58_1.cpp', 'fm_primary_shortfamily_v2_00195c58_2.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT,check=True)
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
