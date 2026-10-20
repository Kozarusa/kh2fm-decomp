from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_nextfamily_v1_0013c820.cpp', 'fm_primary_nextfamily_v1_0013e5a8.cpp', 'fm_primary_nextfamily_v1_0013e610.cpp', 'fm_primary_nextfamily_v1_0013f828.cpp', 'fm_primary_nextfamily_v1_00140850.cpp', 'fm_primary_nextfamily_v1_00141010.cpp', 'fm_primary_nextfamily_v1_00143470.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
