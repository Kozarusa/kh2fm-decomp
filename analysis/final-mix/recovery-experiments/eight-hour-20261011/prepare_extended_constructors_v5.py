from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('001ae9a0','001aea00'):
    text=(base/f'eight_hour_{address}_v4_float_alias_and_address_1.cpp').read_text().replace('asm volatile("addiu %0,%1,1648"','asm("addiu %0,%1,1648"')
    sources[f'eight_hour_{address}_v5_nonvolatile_address.cpp']=text
for address in ('00185b00','00185b70'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_v2_table_lifetime_0.cpp').read_text()
        qualifier=' volatile' if marker else ''
        expression=f'register u32* receiver asm("$4");\n asm{qualifier}("daddu %0,%1,$0" : "=r"(receiver) : "r"(object),"m"(object[700]),"m"(*object),"m"(object[0x162]));\n'
        text=text.replace('register f32* scale', expression+' register f32* scale').replace('func_0016a090(object)', 'func_0016a090(receiver)')
        if address=='00185b70':
            text=text.replace('0036c900','0036c904')
        sources[f'eight_hour_{address}_v5_receiver_transport_{marker}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'extended-constructor-v5-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors_v5.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','extended-constructor-v5-variants.json'))
