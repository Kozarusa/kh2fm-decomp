import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_002f3cd8_99c0af72_bulk.cpp', 'fm_queue_primary_002f3cd8_99c0af72_split.cpp', 'fm_queue_primary_002f4000_cc90d802_bulk.cpp', 'fm_queue_primary_002f4000_cc90d802_split.cpp']:
 subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(p/name),"--summary"],check=True)
