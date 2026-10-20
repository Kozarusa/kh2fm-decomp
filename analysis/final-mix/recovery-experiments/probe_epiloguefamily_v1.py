from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_epiloguefamily_v1_0014dc48_1.cpp', 'fm_primary_epiloguefamily_v1_0014dc48_2.cpp', 'fm_primary_epiloguefamily_v1_0014dc48_3.cpp', 'fm_primary_epiloguefamily_v1_0014dc48_4.cpp', 'fm_primary_epiloguefamily_v1_0014dc48_5.cpp', 'fm_primary_epiloguefamily_v1_0014dca8_1.cpp', 'fm_primary_epiloguefamily_v1_0014dca8_2.cpp', 'fm_primary_epiloguefamily_v1_0014dca8_3.cpp', 'fm_primary_epiloguefamily_v1_0014dca8_4.cpp', 'fm_primary_epiloguefamily_v1_0014dca8_5.cpp', 'fm_primary_epiloguefamily_v1_002e5f70_1.cpp', 'fm_primary_epiloguefamily_v1_002e5f70_2.cpp', 'fm_primary_epiloguefamily_v1_002e5f70_3.cpp', 'fm_primary_epiloguefamily_v1_002e5f70_4.cpp', 'fm_primary_epiloguefamily_v1_002e5f70_5.cpp', 'fm_primary_epiloguefamily_v1_001dc488_1.cpp', 'fm_primary_epiloguefamily_v1_001dc488_2.cpp', 'fm_primary_epiloguefamily_v1_001dc488_3.cpp', 'fm_primary_epiloguefamily_v1_001de948_1.cpp', 'fm_primary_epiloguefamily_v1_001de948_2.cpp', 'fm_primary_epiloguefamily_v1_001de948_3.cpp', 'fm_primary_epiloguefamily_v1_001e0128_1.cpp', 'fm_primary_epiloguefamily_v1_001e0128_2.cpp', 'fm_primary_epiloguefamily_v1_001e0128_3.cpp', 'fm_primary_epiloguefamily_v1_001e0188_1.cpp', 'fm_primary_epiloguefamily_v1_001e0188_2.cpp', 'fm_primary_epiloguefamily_v1_001e0188_3.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
