from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
text = (base / 'eight_hour_00256b80_v3_high_address_0.cpp').read_text()
text = text.replace('register u32 high asm("$14")=0x00360000;\n register s32 stride asm("$15")=408;', 'register s32 stride asm("$15")=408;\n register u32 high asm("$14")=0x00360000;')
sources['eight_hour_00256b80_v4_declaration_order.cpp'] = text
for marker in (0, 1):
    text = (base / 'eight_hour_001de910_clear_pair_0.cpp').read_text()
    text = text.replace('D_01d9e348[0]=0;', 'register u32* cursor asm("$14")=D_01d9e348;\n asm("" : "+r"(cursor) : "m"(D_01d9e348[0]));\n D_01d9e348[0]=0;').replace('D_01d9e348[1]=0;', 'cursor[1]=0;')
    if marker:
        text = text.replace('asm("" : "+r"(cursor) : "m"(D_01d9e348[0]));', 'asm("" : : "r"(cursor) : "memory");')
    sources[f'eight_hour_001de910_v4_cursor_dependency_{marker}.cpp'] = text
for marker in (0, 1):
    text = (base / 'eight_hour_0031e0b8_v3_store_order_1.cpp').read_text()
    text = text.replace('asm("" : "+r"(first),"+r"(second));', 'asm("" : "+r"(first));\n asm("" : "+r"(second));' if marker == 0 else 'asm("" : "+r"(second));\n asm("" : "+r"(first));')
    sources[f'eight_hour_0031e0b8_v4_separate_addresses_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'fresh-44-v4-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_fresh_44_v4.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'fresh-44-v4-variants.json'))
