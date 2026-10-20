from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('0014ba20','0014ba90'):
    for marker in (0,1):
        text=(base/f'eight_hour_{address}_v2_packed_groups_0.cpp').read_text()
        expression='asm("" : "+r"(object));' if marker==0 else 'asm("" : "+r"(object) : "m"(*(u64*)(object+0x40)),"m"(*(u64*)(object+0x42)),"m"(*(u64*)(object+0x44)),"m"(*(u64*)(object+0x46)));'
        text=text.replace('*object=(u32)&D_00349da8;', '*object=(u32)&D_00349da8;\n '+expression)
        sources[f'eight_hour_{address}_v4_object_lifetime_{marker}.cpp']=text
for mask in (1,2,3):
    text=(base/'eight_hour_002c1aa0_three_argument_constructor_0.cpp').read_text()
    if mask&1:
        text=text.replace('object[0x2b9]=0;', '(*(volatile u32*)(object+0x2b9))=0;')
    if mask&2:
        text=text.replace('*(u8*)(object+0x2ba)=0;', '*(volatile u8*)(object+0x2ba)=0;')
    sources[f'eight_hour_002c1aa0_v4_volatile_clears_{mask}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v4-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v4.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v4-variants.json'))
