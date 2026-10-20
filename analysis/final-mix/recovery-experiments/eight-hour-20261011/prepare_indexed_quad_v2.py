from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = json.loads((base / 'indexed-quad-variants.json').read_text())
new = []
for name in names:
    replacement = name.replace('_0023e788_', '_0023e788_v2_')
    (base / replacement).write_text((base / name).read_text().replace('extern "C" ', ''))
    new.append(replacement)
(base / 'indexed-quad-v2-variants.json').write_text(json.dumps(new))
(base / 'probe_indexed_quad_v2.py').write_text((base / 'probe_indexed_quad.py').read_text().replace('indexed-quad-variants.json', 'indexed-quad-v2-variants.json'))
