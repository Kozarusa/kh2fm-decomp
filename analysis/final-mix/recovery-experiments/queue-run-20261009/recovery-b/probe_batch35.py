from pathlib import Path
import subprocess,json
base=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b')
for source in [base/name for name in ["recovery_b_00307f40_9168140f_curated.cpp","recovery_b_0030ec28_d9b87253_curated.cpp"]]:
 with source.with_suffix(".probe.log").open("w") as log:
  r=subprocess.run(["python3",'/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py',str(source),"--summary"],stdout=log,stderr=subprocess.STDOUT)
 if r.returncode: print(source.name,"FAILED",flush=True); continue
 proof=json.loads(source.with_suffix(".verification.json").read_text())["rows"][0]
 print(source.name,proof["exact_match"],proof["compiled_size"],flush=True)
