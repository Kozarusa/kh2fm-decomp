import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_002f42e8_ad38a737_clamp.cpp', 'fm_queue_primary_00222868_223774df_normalize2.cpp']:
 subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(p/name),"--summary"],check=True)
