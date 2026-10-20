from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for pin in (0, 1):
    name = f'eight_hour_00173270_virtual_{pin}.cpp'
    text = '#include "../common/types.h"\ntypedef void (*Callback)(u32);\nvoid func_00173270(u32* owner)\n{\n register u32 object asm("$4")=*owner;\n'
    if pin:
        text += ' asm("" : "+r"(object));\n'
    text += ' register u32 table asm("$14")=*(u32*)object;\n register Callback callback asm("$15")=*(Callback*)(table+32);\n callback(object);\n}\n'
    (base / name).write_text(text)
    names.append(name)
for pin in (0, 1):
    name = f'eight_hour_001bd3e0_masked_call_{pin}.cpp'
    text = '#include "../common/types.h"\nextern "C" s32 func_001bd418(u32);\ns32 func_001bd3e0(u32 object)\n{\n register u32 mask asm("$14")=0x02000000;\n'
    if pin:
        text += ' asm("" : "+r"(mask));\n'
    text += ' u32 child=*(u32*)(object+2528);\n if(*(u32*)(child+1416)&mask)return 0;\n return func_001bd418(object);\n}\n'
    (base / name).write_text(text)
    names.append(name)
for pin in (0, 1):
    name = f'eight_hour_00241fd0_allocate_{pin}.cpp'
    text = '#include "../common/types.h"\nextern "C" u32 func_001063f0(s32);\nextern "C" void func_00242088(u32*);\nvoid func_00241fd0(u32* object,u32 value)\n{\n'
    if pin:
        text += ' register u32* saved asm("$16")=object;\n asm("" : "+r"(saved));\n'
    else:
        text += ' u32* saved=object;\n'
    text += ' saved[0]=value;\n saved[1]=func_001063f0(1024);\n func_00242088(saved);\n}\n'
    (base / name).write_text(text)
    names.append(name)
(base / 'object-forwarding-variants.json').write_text(json.dumps(names))
(base / 'probe_object_forwarding.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'object-forwarding-variants.json'))
