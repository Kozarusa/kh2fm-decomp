import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_00222678_4ed3610e_max.cpp', 'fm_queue_primary_002229a0_98dc28cf_length3.cpp']:
 subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(p/name),"--summary"],check=True)
