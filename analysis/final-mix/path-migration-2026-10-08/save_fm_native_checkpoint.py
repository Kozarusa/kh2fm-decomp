"""Save the verified Linux build and manifest in the FM workspace checkpoint."""
import hashlib
import json
from pathlib import Path
import shutil
import tarfile

stage = Path('/root/kh2fm-build')
saved = Path('/mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/native-build')
verification = json.loads((stage / 'out/native-build-verification.json').read_text())
expected = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
assert hashlib.sha256((stage / 'kh2.elf').read_bytes()).hexdigest() == expected
assert verification['rebuilt_sha256'] == expected
paths = {'kh2.elf': 'kh2.elf', 'linked.tmp.elf': 'out/linked.tmp.elf',
         'native-build-verification.json': 'out/native-build-verification.json',
         'compiler-range-verification.json': 'out/compiler-range-verification.json',
         'build-input-provenance.json': 'out/build-input-provenance.json',
         'objdiff-linux-stage.json': 'out/objdiff/report.json'}
for name, relative in paths.items():
    assert (stage / relative).is_file(), relative
for name, relative in paths.items():
    shutil.copyfile(stage / relative, saved / name)
with tarfile.open(saved / 'compiled-objects.tar.gz', 'w:gz') as archive:
    archive.add(stage / 'out/build', arcname='out/build')
manifest = []
for name in sorted([*paths, 'compiled-objects.tar.gz']):
    data = (saved / name).read_bytes()
    manifest.append({'file': name, 'size': len(data), 'sha256': hashlib.sha256(data).hexdigest()})
(saved / 'artifact-manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
print(f'Saved verified build: {verification["unmodified_compiled_symbol_matches"]} exact compiler matches')
