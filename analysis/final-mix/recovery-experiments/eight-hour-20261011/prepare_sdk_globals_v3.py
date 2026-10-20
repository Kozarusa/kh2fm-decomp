from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_0030a690_v2_0.cpp').read_text()
names = []
for index in (0, 1):
    name = f'eight_hour_0030a690_v3_{index}.cpp'
    text = original.replace('func_002fde18((u8*)(callback-30296),0,4);', 'register u8* target asm("$4")=(u8*)(callback-30296);\n asm("" : "+r"(target));\n func_002fde18(target,0,4);')
    if index:
        text = text.replace('asm("" : "+r"(target));', 'asm("" : "+r"(target) : "m"(*(u32*)(address+0x6164)));')
    (base / name).write_text(text)
    names.append(name)
(base / 'sdk-global-v3-variants.json').write_text(json.dumps(names))
(base / 'probe_sdk_globals_v3.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'sdk-global-v3-variants.json'))
