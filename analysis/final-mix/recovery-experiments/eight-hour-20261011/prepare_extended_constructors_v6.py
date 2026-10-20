from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('001ae9a0','001aea00'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_v5_nonvolatile_address.cpp').read_text()
        qualifier=' volatile' if marker else ''
        text=text.replace('asm("" : "+r"(flags) : "m"(*object));\n object[0x162]=flags|0x400;', f'asm{qualifier}("ori %0,%0,0x400" : "+r"(flags) : "m"(*object));\n object[0x162]=flags;')
        sources[f'eight_hour_{address}_v6_flag_transport_{marker}.cpp']=text
for address in ('00185b00','00185b70'):
    text=(base/f'eight_hour_{address}_v2_table_lifetime_0.cpp').read_text().replace('object[700]=0;', '*(f32*)(object+700)=0.0f;').replace('"m"(object[700])','"m"(*(f32*)(object+700))')
    if address=='00185b70':
        text=text.replace('0036c900','0036c904')
    sources[f'eight_hour_{address}_v6_float_clear.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'extended-constructor-v6-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors_v6.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','extended-constructor-v6-variants.json'))
