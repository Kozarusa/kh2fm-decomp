from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address,global_address in (('0014ba20','0036b0d8'),('0014ba90','0036b0e0')):
    for profile in (0,1):
        first=' *(u64*)(object+0x42)=14;\n *(u64*)(object+0x44)=data;\n *(u64*)(object+0x40)=flags|0x8001;\n *(u64*)(object+0x46)=64;\n'
        second=' *(u64*)(object+0x48)=flags|0x8001;\n *(u64*)(object+0x4a)=14;\n *(u64*)(object+0x4c)=data;\n *(u64*)(object+0x4e)=64;\n'
        table=' *object=(u32)&D_00349da8;\n'
        text=f'#include "../common/types.h"\nextern "C" u8 D_00349da8;\nextern "C" u64 D_{global_address};\nextern "C" void func_0014b290(u32*);\nvoid func_{address}(u32* object)\n{{\n func_0014b290(object);\n u64 data=D_{global_address};\n register u64 flags asm("$14")=1ULL<<60;\n asm("" : "+r"(flags));\n'
        text+=second+table+first if profile==0 else second+first+table
        sources[f'eight_hour_{address}_v8_reverse_groups_{profile}.cpp']=text+'}\n'
for profile in (0,1):
    text=(base/('eight_hour_002c1aa0_three_argument_constructor_0.cpp' if profile==0 else 'eight_hour_002c1aa0_v3_table_dependency_1.cpp')).read_text()
    text=text.replace('object[0x2b9]=0;', '*(u8*)(object+0x2ba)=0;').replace('*(u8*)(object+0x2ba)=0;\n}', 'object[0x2b9]=0;\n}')
    sources[f'eight_hour_002c1aa0_v8_reverse_clears_{profile}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v8-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v8.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v8-variants.json'))
