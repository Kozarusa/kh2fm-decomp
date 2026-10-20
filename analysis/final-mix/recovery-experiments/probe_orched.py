import json,subprocess
from pathlib import Path
w=Path("/mnt/c/Users/KoZa/Documents/AGENTS/Codex")
for relative in json.loads((w/"analysis/final-mix/recovery-experiments/orched-curated-inputs.json").read_text()):
 source=w/relative
 log_path=source.with_suffix(".independent-probe.log")
 attempt=1
 while log_path.exists():
  attempt+=1; log_path=source.with_suffix(".independent-probe-"+str(attempt)+".log")
 with log_path.open("x") as log:
  subprocess.run(["python3",str(w.parent/"Public/tools/kh2-audit/probe_fm_source.py"),str(source),"--summary"],stdout=log,stderr=subprocess.STDOUT,check=True)
 proof=json.loads(source.with_suffix(".verification.json").read_text())
 assert all(r["exact_match"] for r in proof["rows"]), source
 print(source.name+": complete independent exact proof; diagnostics saved",flush=True)
