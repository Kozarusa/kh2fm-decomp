from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_callbackschedule_v3_001c0c38.cpp', 'fm_primary_callbackschedule_v3_001c10f8.cpp', 'fm_primary_callbackschedule_v3_001d23e0.cpp', 'fm_primary_callbackschedule_v3_001d30c0.cpp', 'fm_primary_callbackschedule_v3_001d7980.cpp', 'fm_primary_callbackschedule_v3_002c22b8.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT,check=True)
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
