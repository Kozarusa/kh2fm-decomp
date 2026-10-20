from pathlib import Path
import subprocess
out=Path(__file__).parent
for source in sorted(out.glob('sa_lookup_*.cpp')):
 linux='/mnt/c/'+source.resolve().as_posix()[3:]
 p=subprocess.run(['wsl','-d','Ubuntu-24.04','-u','root','--','python3','/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py',linux,'--summary'],capture_output=True,text=True)
 source.with_suffix('.probe.log').write_text(p.stdout+p.stderr)
 print(source.name,p.returncode,p.stdout[-300:],p.stderr[-300:])
