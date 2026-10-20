import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_002229d8_749663f3_vectorlength.cpp', 'fm_queue_primary_00222978_d4d97a36_vectorsqrt.cpp']:
 subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(p/name),"--summary"],check=True)
