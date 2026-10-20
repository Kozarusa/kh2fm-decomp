from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_globalstruct_v4_00102c90_1.cpp', 'fm_primary_globalstruct_v4_00102c90_2.cpp', 'fm_primary_globalstruct_v4_00102c90_3.cpp', 'fm_primary_globalstruct_v4_00102c90_4.cpp', 'fm_primary_globalstruct_v4_00103080_1.cpp', 'fm_primary_globalstruct_v4_00103080_2.cpp', 'fm_primary_globalstruct_v4_00103080_3.cpp', 'fm_primary_globalstruct_v4_00103080_4.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT,check=True)
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
