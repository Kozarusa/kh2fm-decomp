import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_001565c0_typedinitializer.cpp', 'fm_queue_primary_001565c0_typedcalls.cpp', 'fm_queue_primary_001565c0_volatilespill.cpp']:
 subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(p/name),"--summary"],check=True)
