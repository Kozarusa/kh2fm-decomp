from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_001ad990_interpolation_0_0.cpp').read_text()
names = []
for index, marker in enumerate(('asm("" : "+r"(output));', 'asm("" : "+r"(output) : "m"(output[1]));', 'asm("" : : "m"(output[1]) : "memory");', 'asm("" : "+f"(end) : "m"(output[1]));')):
    name = f'eight_hour_001ad990_v4_{index}.cpp'
    (base / name).write_text(original.replace('output[1]=zero;', 'output[1]=zero;\n ' + marker))
    names.append(name)
(base / 'float-interpolation-v4-variants.json').write_text(json.dumps(names))
(base / 'probe_float_interpolation_v4.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'float-interpolation-v4-variants.json'))
