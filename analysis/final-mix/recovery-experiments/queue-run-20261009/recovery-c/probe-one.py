import subprocess,json,sys,sqlite3
from pathlib import Path
root=Path(__file__).resolve().parents[6]
source=Path(sys.argv[1]).resolve()
db=sqlite3.connect('file:'+str(root/'Codex/analysis/final-mix/worker-coordination/recovery-queue.sqlite3')+'?mode=ro',uri=True)
if db.execute("select value from control where key='paused'").fetchone()[0]=='true':
 print('Paused; no compiler probe launched.');sys.exit(2)
linux='/mnt/c/'+str(source).replace('\\','/')[3:]
r=subprocess.run(['wsl','-d','Ubuntu-24.04','-u','root','--','python3','/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py',linux,'--summary'],capture_output=True,text=True)
source.with_suffix('.log').write_text(r.stdout+r.stderr)
if r.returncode:
 print(r.stdout+r.stderr);sys.exit(r.returncode)
rows=json.loads(source.with_suffix('.verification.json').read_text())['rows']
for row in rows:
 a,b=row['compiled_hex'],row['target_hex']
 print(row['address'],row['compiled_size'],row['target_size'],row['exact_match'],[j//8 for j in range(0,min(len(a),len(b)),8) if a[j:j+8]!=b[j:j+8]])
