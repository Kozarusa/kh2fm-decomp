import subprocess,json
from pathlib import Path
p=Path(__file__).resolve().parent
for name in ['fm_queue_primary_00209fb8_a3397ee1_random5.cpp', 'fm_queue_primary_0020b410_c42b88de_random5.cpp']:
 source=p/name
 with source.with_suffix(".probe.log").open("x") as log:
  subprocess.run(["python3","/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py",str(source),"--summary"],stdout=log,stderr=subprocess.STDOUT,check=True)
 r=json.loads(source.with_suffix(".verification.json").read_text())["rows"][0];print(name,r["compiled_size"],r["target_size"],r["exact_match"],flush=True)
