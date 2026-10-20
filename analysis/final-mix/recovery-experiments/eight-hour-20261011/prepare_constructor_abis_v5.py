from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for mask in (1,2,3):
    text=(base/'eight_hour_002c1aa0_v3_table_dependency_1.cpp').read_text()
    if mask&1:
        text=text.replace('object[0x2b9]=0;', '(*(volatile u32*)(object+0x2b9))=0;')
    if mask&2:
        text=text.replace('*(u8*)(object+0x2ba)=0;', '*(volatile u8*)(object+0x2ba)=0;')
    sources[f'eight_hour_002c1aa0_v5_table_volatile_{mask}.cpp']=text
for address in ('0014ba20','0014ba90'):
    for profile in (0,1):
        text=(base/f'eight_hour_{address}_v4_object_lifetime_0.cpp').read_text()
        text=text.replace('*(u64*)(object+0x42)=14;', 'register u64 fourteen asm("$13")=14;\n asm("" : "+r"(fourteen));\n *(u64*)(object+0x42)=fourteen;').replace('*(u64*)(object+0x4a)=14;', '*(volatile u64*)(object+0x4a)=fourteen;')
        if profile:
            text=text.replace('*(u64*)(object+0x46)=64;', 'register u64 sixtyfour asm("$12")=64;\n asm("" : "+r"(sixtyfour));\n *(u64*)(object+0x46)=sixtyfour;').replace('*(u64*)(object+0x4e)=64;', '*(volatile u64*)(object+0x4e)=sixtyfour;')
        else:
            text=text.replace('*(u64*)(object+0x4e)=64;', '*(volatile u64*)(object+0x4e)=64;')
        text=text.replace('*(u64*)(object+0x48)', '*(volatile u64*)(object+0x48)').replace('*(u64*)(object+0x4c)', '*(volatile u64*)(object+0x4c)')
        sources[f'eight_hour_{address}_v5_bound_constants_{profile}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v5-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v5.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v5-variants.json'))
