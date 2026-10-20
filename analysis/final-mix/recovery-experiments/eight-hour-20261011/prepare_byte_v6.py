from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_0015cbb8_v5_byte_dependencies_2.cpp').read_text()
names = []
for index in (0, 1):
    name = f'eight_hour_0015cbb8_v6_word_payloads_{index}.cpp'
    text = original.replace('u8 a,u8 b,u8 c,u8 d', 'u8 a,u32 b,u32 c,u32 d')
    text = text.replace('asm("" : : "r"(b),"r"(c),"r"(d));', 'asm("" : "+r"(b),"+r"(c),"+r"(d) : "m"(*(u8*)(high+0x3700)));\n b=(u8)b;c=(u8)c;d=(u8)d;\n asm("" : : "r"(b),"r"(c),"r"(d));')
    if index:
        text = text.replace('asm("" : : "r"(b),"r"(c),"r"(d));', 'asm("" : "+r"(b),"+r"(c),"+r"(d));')
    (base / name).write_text(text)
    names.append(name)
(base / 'byte-v6-variants.json').write_text(json.dumps(names))
(base / 'probe_byte_v6.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'byte-v6-variants.json'))
