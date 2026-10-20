from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
text = (base / 'eight_hour_001c0268_bit_table_1.cpp').read_text().replace('mask<<=index;', 'mask<<=index;\n asm("" : "+r"(mask));')
sources['eight_hour_001c0268_v2_pin_shift.cpp'] = text
text = (base / 'eight_hour_0031e0b8_double_vtable_1.cpp').read_text().replace('object[0]=first;', '(*(volatile u32*)object)=first;').replace('object[20]=second;', '(*(volatile u32*)(object+20))=second;')
sources['eight_hour_0031e0b8_v2_volatile.cpp'] = text
for marker in range(3):
    text = (base / 'eight_hour_00256b80_stride_0.cpp').read_text().replace('void func_00139d78(u32);', 'u32 func_00139d78(u32);')
    ending = ('asm volatile("");', 'asm("" : : "r"(result));', 'asm("" : "+r"(result));')[marker]
    text = text.replace('func_00139d78(D_0035f028+offset);', 'u32 result=func_00139d78(D_0035f028+offset);\n ' + ending)
    sources[f'eight_hour_00256b80_v2_result_{marker}.cpp'] = text
for marker in (0, 1):
    text = '#include "../common/types.h"\nvoid func_0015cbb8(u8 a,u8 b,u8 c,u8 d)\n{\n register u32 high asm("$14")=0x004f0000;\n asm("" : "+r"(high));\n register volatile u8* cursor asm("$15")=(volatile u8*)(high+0x3700);\n'
    text += ' asm("" : "+r"(cursor) : "r"(a));\n' if marker else ' asm("" : "+r"(cursor));\n'
    text += ' *(volatile u8*)(high+0x3700)=a;\n cursor[1]=b;\n cursor[3]=d;\n cursor[2]=c;\n}\n'
    sources[f'eight_hour_0015cbb8_v2_explicit_cursor_{marker}.cpp'] = text
for marker in (0, 1):
    text = '#include "../common/types.h"\nextern "C" void func_001de690(s32);\nextern "C" void func_001dced0(void);\nvoid func_001de910(void)\n{\n func_001de690(0);\n register u32 high asm("$15")=0x01da0000;\n asm("" : "+r"(high));\n register u32* cursor asm("$14")=(u32*)(high-7352);\n'
    if marker:
        text += ' asm("" : "+r"(cursor));\n'
    text += ' *(u32*)(high-7352)=0;\n cursor[1]=0;\n func_001dced0();\n}\n'
    sources[f'eight_hour_001de910_v2_explicit_cursor_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'fresh-44-v2-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_fresh_44_v2.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'fresh-44-v2-variants.json'))
