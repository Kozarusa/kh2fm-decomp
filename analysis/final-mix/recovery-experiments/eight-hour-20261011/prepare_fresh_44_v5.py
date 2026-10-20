from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
for marker in range(3):
    text = (base / 'eight_hour_0015cbb8_v2_explicit_cursor_0.cpp').read_text().replace('register volatile u8* cursor', 'register u8* cursor').replace('(volatile u8*)(high+', '(u8*)(high+').replace('*(volatile u8*)(high+', '*(u8*)(high+')
    text = text.replace('asm("" : "+r"(cursor));', 'asm("" : "+r"(cursor) : "m"(*(u8*)(high+0x3700)));')
    if marker == 0:
        text = text.replace('=a;', '=a;\n asm("" : : "r"(b),"r"(c),"r"(d) : "memory");')
    elif marker == 1:
        text = text.replace('cursor[1]=b;', 'cursor[1]=b;\n asm("" : "+m"(cursor[1]),"+m"(cursor[2]),"+m"(cursor[3]));').replace('cursor[3]=d;', 'cursor[3]=d;\n asm("" : "+m"(cursor[2]),"+m"(cursor[3]));')
    else:
        text = text.replace('cursor[1]=b;', 'asm("" : : "r"(b),"r"(c),"r"(d));\n (*(volatile u8*)(cursor+1))=b;').replace('cursor[3]=d;', '(*(volatile u8*)(cursor+3))=d;').replace('cursor[2]=c;', '(*(volatile u8*)(cursor+2))=c;')
    sources[f'eight_hour_0015cbb8_v5_byte_dependencies_{marker}.cpp'] = text
for marker in (0, 1):
    text = '#include "../common/types.h"\nextern "C" void func_00106420(u32*);\nvoid func_0031e0b8(u32* object)\n{\n register u32 first asm("$14")=0x00350000;\n asm("" : "+r"(first));\n register u32 second asm("$13");\n asm volatile("lui %0,0x35" : "=r"(second));\n first-=29352;\n second-=31080;\n object[0]=first;\n'
    text += ' asm("" : "+m"(object[0]),"+m"(object[20]));\n' if marker else ' asm("" : : : "memory");\n'
    text += ' object[20]=second;\n func_00106420(object);\n}\n'
    sources[f'eight_hour_0031e0b8_v5_high_transport_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'fresh-44-v5-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_fresh_44_v5.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'fresh-44-v5-variants.json'))
