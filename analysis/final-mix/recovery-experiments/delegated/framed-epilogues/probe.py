from pathlib import Path
import json,subprocess
out=Path(__file__).resolve().parent
audit=out.parents[5]/'Public/tools/kh2-audit/probe_fm_source.py'
for source in sorted(out.glob('sa_frame_*.cpp')):
 with source.with_suffix('.probe.log').open('w') as log:
  rc=subprocess.run(['python3',str(audit),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT).returncode
 if rc: print(source.name,'FAILED',rc,flush=True); continue
 p=json.loads(source.with_suffix('.verification.json').read_text())
 print(source.name,[(r['exact_match'],r['compiled_size'],r['target_size'],r['compiled_hex']) for r in p['rows']],flush=True)
