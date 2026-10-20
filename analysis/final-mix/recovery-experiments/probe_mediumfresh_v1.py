from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_mediumfresh_v1_0011eea8.cpp', 'fm_primary_mediumfresh_v1_00123d40.cpp', 'fm_primary_mediumfresh_v1_00124c48.cpp', 'fm_primary_mediumfresh_v1_00127d40.cpp', 'fm_primary_mediumfresh_v1_001317a8.cpp', 'fm_primary_mediumfresh_v1_00132018.cpp', 'fm_primary_mediumfresh_v1_00132f38.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
