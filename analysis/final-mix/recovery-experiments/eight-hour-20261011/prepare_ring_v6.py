from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_00308dc0_v5_division_primitive_0.cpp').read_text()
names = []
for index in (0, 1):
    name = f'eight_hour_00308dc0_v6_remainder_lifetime_{index}.cpp'
    text = original.replace('object[9]=next;', 'asm("" : "+r"(index) : "r"(next));\n object[9]=next;')
    if index:
        text = text.replace('return first+index*64;', 's32 result=first+index*64;\n asm("" : : "r"(first));\n return result;')
    (base / name).write_text(text)
    names.append(name)
(base / 'ring-v6-variants.json').write_text(json.dumps(names))
(base / 'probe_ring_v6.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'ring-v6-variants.json'))
