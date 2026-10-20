"""Synchronize three authorized boundary changes after checking staged originals."""
import hashlib
import json
from pathlib import Path
import shutil
import sys

STAGE = Path('/root/kh2fm-build')
WORKSPACE = Path('/mnt/c/Users/KoZa/Documents/ChatGPT')
EXPECTED = {
    'src/anon/tiny.cpp': '6ede207688545e2d3acc3ae15571a8a4a3607926ac39bbacfa5f2961c8b822e2',
    'functions.tsv': '25b632e212ecdc458da8e4e0744d401ecb6c1769472fa285fa1067370fcd6042',
    'layout.tsv': '6431acb34b0216cef26054c0496b026b48b072a210fb6820b5b137d33b1c7d5c',
}
receipt = WORKSPACE / 'analysis/final-mix/native-build/boundary-sync.json'
if len(sys.argv) == 2:
    manifest = Path(sys.argv[1])
    rows = json.loads(manifest.read_text())
    EXPECTED = {row['file']: row['expected_stage_sha256'] for row in rows}
    receipt = manifest.with_name(manifest.stem + '-receipt.json')
changes = []
for relative, original_hash in EXPECTED.items():
    if Path(relative).is_absolute() or '..' in Path(relative).parts:
        raise ValueError(f'Input path must remain inside the build root: {relative}')
    source = WORKSPACE / 'tools/kh2-reference' / relative
    target = STAGE / relative
    source_hash = hashlib.sha256(source.read_bytes()).hexdigest()
    target_hash = hashlib.sha256(target.read_bytes()).hexdigest() if target.exists() else None
    if target_hash not in (original_hash, source_hash):
        raise RuntimeError(f'Unrecognized staged change; refusing overwrite: {relative}')
    changes.append({'file': relative, 'previous_sha256': target_hash, 'source_sha256': source_hash})
# Validate every target before the first write.
for change in changes:
    relative = change['file']
    shutil.copyfile(WORKSPACE / 'tools/kh2-reference' / relative, STAGE / relative)
    assert hashlib.sha256((STAGE / relative).read_bytes()).hexdigest() == change['source_sha256']
receipt.write_text(json.dumps(changes, indent=2) + '\n')
print(f'Verified and synchronized {len(changes)} FM input files')
