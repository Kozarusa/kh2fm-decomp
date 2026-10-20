import json,subprocess
from pathlib import Path
workspace=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
audit=workspace.parent/'Public/tools/kh2-audit'
for relative in json.loads((workspace/'analysis/final-mix/recovery-experiments/queuealpha-curated-inputs.json').read_text()):
 subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(workspace/relative),'--summary'],check=True)
