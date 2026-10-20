"""Probe only isolated angle variants, preserving every compiler diagnostic."""
from pathlib import Path
import json
import subprocess
import sys

base = Path(__file__).resolve().parent
workspace = base.parents[3]
helper = workspace.parent / 'Public/tools/kh2-audit/probe_fm_source.py'
for name in json.loads((base / 'extended-constructor-v4-variants.json').read_text()):
    source = base / name
    log = source.with_suffix('.probe.log')
    with log.open('x') as stream:
        result = subprocess.run([sys.executable, str(helper), str(source), '--summary'], stdout=stream, stderr=subprocess.STDOUT)
    if result.returncode:
        print(name + ': compiler failure; preserved diagnostics', flush=True)
        continue
    proof = json.loads(source.with_suffix('.verification.json').read_text())
    row = proof['rows'][0]
    original = bytes.fromhex(row['target_hex'])
    compiled = bytes.fromhex(row['compiled_hex'])
    differences = sum(compiled[i:i+4] != original[i:i+4] for i in range(0, max(len(original), len(compiled)), 4))
    print(f'{name}: {row["compiled_size"]}/{row["target_size"]} bytes; {differences} differing words; exact={row["exact_match"]}', flush=True)
