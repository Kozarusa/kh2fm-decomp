import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['volatile','barrier','valuebarrier']:
 subprocess.run(['python3','/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py',str(p/('fm_queue_primary_00305ce0_'+name+'.cpp')),'--summary'],check=True)
