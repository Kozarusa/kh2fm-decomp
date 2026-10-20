from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for shape in (0, 1):
    for transport in (0, 1, 2):
        name = f'eight_hour_00311050_v4_payload_{shape}_{transport}.cpp'
        first = 's32' if transport < 2 else 'u64'
        text = f'#include "../common/types.h"\nextern "C" s32 func_00305a50({first},void*);\nvoid func_00311050(u32 value,s8 flag)\n{{\n'
        if shape:
            text += ' struct Payload{u32 value;s32 flag;};\n Payload payload={value,flag};\n'
        else:
            text += ' s32 payload[2]={(s32)value,(s32)flag};\n'
        if transport == 1:
            text += ' register s32 operation asm("$4");\n asm("li %0,3" : "=r"(operation) : "m"(payload));\n func_00305a50(operation,&payload);\n'
        else:
            text += ' func_00305a50(3,&payload);\n'
        text += '}\n'
        (base / name).write_text(text)
        names.append(name)
(base / 'sdk-stack-v4-variants.json').write_text(json.dumps(names))
(base / 'probe_sdk_stack_v4.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'sdk-stack-v4-variants.json'))
