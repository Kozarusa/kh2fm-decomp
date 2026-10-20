import json,subprocess
from pathlib import Path
w=Path("/mnt/c/Users/KoZa/Documents/AGENTS/Codex")
for relative in json.loads((w/"analysis/final-mix/recovery-experiments/queuebeta-curated-inputs.json").read_text()):
 subprocess.run(["python3",str(w.parent/"Public/tools/kh2-audit/probe_fm_source.py"),str(w/relative),"--summary"],check=True)
