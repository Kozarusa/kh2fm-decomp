from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_0030a690_v2_0.cpp').read_text()
names = []
for index in range(3):
    name = f'eight_hour_0030a690_v4_{index}.cpp'
    if index < 2:
        word = ' volatile' if index else ''
        expression = f'asm{word}("addiu %0,%0,-30296" : "+r"(callback));\n func_002fde18((u8*)callback,0,4);'
    else:
        expression = 'callback-=30296;\n register u32 zero asm("$5")=0;\n asm("" : "+r"(callback),"+r"(zero));\n func_002fde18((u8*)callback,zero,4);'
    (base / name).write_text(original.replace('func_002fde18((u8*)(callback-30296),0,4);', expression))
    names.append(name)
(base / 'sdk-global-v4-variants.json').write_text(json.dumps(names))
(base / 'probe_sdk_globals_v4.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'sdk-global-v4-variants.json'))
