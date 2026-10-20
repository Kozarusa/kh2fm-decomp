from pathlib import Path
import subprocess,json
base=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b')
for source in [base/f"recovery_b_002713a0_55ee6b2a_{v}.cpp" for v in ["pinnedcount","edgebarrier","edgeinput"]]+[base/f"recovery_b_002f35e8_93a09841_{v}.cpp" for v in ["guardmarker","fixed","pinnedbase"]]:
 with source.with_suffix(".probe.log").open("w") as log:
  r=subprocess.run(["python3",'/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py',str(source),"--summary"],stdout=log,stderr=subprocess.STDOUT)
 if r.returncode: print(source.name,"FAILED",flush=True); continue
 proof=json.loads(source.with_suffix(".verification.json").read_text())["rows"][0]
 print(source.name,proof["exact_match"],proof["compiled_size"],flush=True)
