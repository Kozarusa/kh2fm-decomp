from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=['fm_primary_linkorder_v1_001d4ef0.cpp', 'fm_primary_linkorder_v1_00265740.cpp', 'fm_primary_linkorder_v1_00265c10.cpp', 'fm_primary_linkorder_v1_00315678.cpp', 'fm_primary_linkorder_v1_00315700.cpp', 'fm_primary_linkorder_v1_00316890.cpp', 'fm_primary_linkorder_v1_0028b7f8.cpp']
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT,check=True)
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
