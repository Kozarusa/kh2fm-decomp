from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_0023e788_v2_asm_0.cpp').read_text()
names = []
for index, expression in enumerate(('(const u8*)(index + (u32)record)', '(const u8*)((s32)index + (s32)record)')):
    name = f'eight_hour_0023e788_v3_{index}.cpp'
    (base / name).write_text(original.replace('record + index', expression))
    names.append(name)
(base / 'indexed-quad-v3-variants.json').write_text(json.dumps(names))
(base / 'probe_indexed_quad_v3.py').write_text((base / 'probe_indexed_quad.py').read_text().replace('indexed-quad-variants.json', 'indexed-quad-v3-variants.json'))
