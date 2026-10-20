from pathlib import Path
import subprocess,json
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
source=ex/'fm_primary_lookupswitch_recovered.cpp'
audit=ex.parents[3]/'Public/tools/kh2-audit'
with source.with_suffix('.probe.log').open('w') as log:
 subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT,check=True)
proof=json.loads(source.with_suffix('.verification.json').read_text())
assert len(proof['rows'])==2 and all(r['exact_match'] for r in proof['rows'])
subprocess.run(['python3',str(ex/'verify_lookupswitch_isolated.py'),source.stem,'primary-lookupswitch-curated-table-proof-v1.json'],check=True)
