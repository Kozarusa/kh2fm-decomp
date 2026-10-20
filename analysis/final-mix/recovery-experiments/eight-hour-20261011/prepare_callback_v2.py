"""Keep the high-word carrier live instead of folding its numeric constant."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for name in json.loads((base / 'callback-variants.json').read_text()):
    source = (base / name).read_text()
    source = source.replace('"+r"(first) : "r"(high)', '"+r"(first),"+r"(high)')
    source = source.replace('"+r"(table) : "r"(high)', '"+r"(table),"+r"(high)')
    source = source.replace('"+r"(first),"+r"(table) : "r"(high)', '"+r"(first),"+r"(table),"+r"(high)')
    destination = name.replace('00102bd8_', '00102bd8_v2_')
    path = base / destination
    assert not path.exists()
    path.write_text(source)
    names.append(destination)
(base / 'callback-v2-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_callback_v2.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'callback-v2-variants.json'"))
print(f'Prepared {len(names)} live-high-word variants.')
