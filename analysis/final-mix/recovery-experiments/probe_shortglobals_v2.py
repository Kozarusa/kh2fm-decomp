from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_shortglobals_v2_00305e20_1.cpp', 'fm_primary_shortglobals_v2_00305e20_2.cpp', 'fm_primary_shortglobals_v2_00305e20_3.cpp', 'fm_primary_shortglobals_v2_0030ec28_1.cpp', 'fm_primary_shortglobals_v2_0030ec28_2.cpp', 'fm_primary_shortglobals_v2_0030ec28_3.cpp', 'fm_primary_shortglobals_v2_001c8a90_1.cpp', 'fm_primary_shortglobals_v2_001c8a90_2.cpp', 'fm_primary_shortglobals_v2_001c8a90_3.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
