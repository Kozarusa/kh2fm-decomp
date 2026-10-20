from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_callbackreturn_v1_001050d8_1.cpp', 'fm_primary_callbackreturn_v1_001050d8_2.cpp', 'fm_primary_callbackreturn_v1_001050d8_3.cpp', 'fm_primary_callbackreturn_v1_0016c7a0_1.cpp', 'fm_primary_callbackreturn_v1_0016c7a0_2.cpp', 'fm_primary_callbackreturn_v1_0016c7a0_3.cpp', 'fm_primary_callbackreturn_v1_0016fac8_1.cpp', 'fm_primary_callbackreturn_v1_0016fac8_2.cpp', 'fm_primary_callbackreturn_v1_0016fac8_3.cpp', 'fm_primary_callbackreturn_v1_00288be8_1.cpp', 'fm_primary_callbackreturn_v1_00288be8_2.cpp', 'fm_primary_callbackreturn_v1_00288be8_3.cpp', 'fm_primary_callbackreturn_v1_0028cc08_1.cpp', 'fm_primary_callbackreturn_v1_0028cc08_2.cpp', 'fm_primary_callbackreturn_v1_0028cc08_3.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
