from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
for marker in (0, 1):
    text = (base / 'eight_hour_001c0268_bit_table_1.cpp').read_text()
    expression = 'asm("" : : "r"(index));' if marker == 0 else 'asm("" : "+r"(index));'
    text = text.replace('return (*(u32*)(object+4)&mask)==0;', 'u32 bits=*(u32*)(object+4)&mask;\n ' + expression + '\n return bits==0;')
    sources[f'eight_hour_001c0268_v3_index_lifetime_{marker}.cpp'] = text
for marker in (0, 1):
    text = (base / 'eight_hour_0031e0b8_double_vtable_1.cpp').read_text()
    expression = 'asm("" : : : "memory");' if marker == 0 else 'asm("" : "+m"(object[0]),"+m"(object[20]));'
    text = text.replace('object[0]=first;', 'object[0]=first;\n ' + expression)
    sources[f'eight_hour_0031e0b8_v3_store_order_{marker}.cpp'] = text
for marker in (0, 1):
    text = (base / 'eight_hour_00256b80_v2_result_1.cpp').read_text()
    text = text.replace('register s32 stride', 'register u32 high asm("$14")=0x00360000;\n register s32 stride')
    text = text.replace('asm("" : "+r"(stride));', 'asm("" : "+r"(stride),"+r"(high));' if marker == 0 else 'asm("" : "+r"(stride));\n asm("" : "+r"(high));')
    text = text.replace('D_0035f028+offset', '*(u32*)(high-4056)+offset')
    sources[f'eight_hour_00256b80_v3_high_address_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'fresh-44-v3-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_fresh_44_v3.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'fresh-44-v3-variants.json'))
