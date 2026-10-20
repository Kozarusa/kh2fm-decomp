from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_globalresidual_v5_0014ec40_1.cpp', 'fm_primary_globalresidual_v5_0014ec40_2.cpp', 'fm_primary_globalresidual_v5_0014fba0_1.cpp', 'fm_primary_globalresidual_v5_0014fba0_2.cpp', 'fm_primary_globalresidual_v5_00153610_1.cpp', 'fm_primary_globalresidual_v5_00153610_2.cpp', 'fm_primary_globalresidual_v5_00153610_3.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
