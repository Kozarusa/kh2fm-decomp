"""Append an orchestrator event and heartbeat its lock; no recovery work."""
from datetime import datetime, timezone
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[1]
stamp = datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ')
event, detail = sys.argv[1], ' '.join(sys.argv[2:])
with (root / 'PROGRESS.md').open('a', encoding='utf-8') as stream:
    stream.write(f'{stamp} | {event} | {detail}\n')
subprocess.run([sys.executable, '-I', str(root / 'tools/orch.py'),
                'lock', 'heartbeat', 'gpt6-orch-oct18'], check=True)


