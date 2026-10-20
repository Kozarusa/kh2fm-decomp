import subprocess
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_00308cd0_volatile.cpp', 'fm_queue_primary_00308cd0_barrier.cpp', 'fm_queue_primary_00308cd0_basebarrier.cpp', 'fm_queue_primary_00305ce0_canonical.cpp', 'fm_queue_primary_00305ce0_canonicalplain.cpp']:
 subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(p/name),"--summary"],check=True)
