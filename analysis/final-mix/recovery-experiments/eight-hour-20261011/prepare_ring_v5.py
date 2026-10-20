from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for index in (0, 1):
    old = f'eight_hour_00308dc0_v4_division_primitive_{index}.cpp'
    name = old.replace('_v4_', '_v5_')
    (base / name).write_text((base / old).read_text().replace('div $zero,', 'div $0,'))
    names.append(name)
(base / 'ring-v5-variants.json').write_text(json.dumps(names))
(base / 'probe_ring_v5.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'ring-v5-variants.json'))
