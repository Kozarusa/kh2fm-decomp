from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('0014ba20','0014ba90'):
    for profile in (0,1):
        text=(base/f'eight_hour_{address}_v5_bound_constants_1.cpp').read_text()
        for offset in ('0x42','0x44','0x40','0x46'):
            text=text.replace(f'*(u64*)(object+{offset})',f'*(volatile u64*)(object+{offset})')
        if profile:
            text=text.replace('*object=(u32)&D_00349da8;', '*(volatile u32*)object=(u32)&D_00349da8;')
        sources[f'eight_hour_{address}_v6_volatile_groups_{profile}.cpp']=text
for marker in (0,1):
    text='#include "../common/types.h"\nextern "C" u8 D_00361b20;\nextern "C" void func_002be770(u32*,u64,u64);\nvoid func_002c1aa0(u32* object,u64 second,u64 third)\n{\n func_002be770(object,second,third);\n register u32 flags asm("$14")=object[0x163];\n register u32 table asm("$15")=(u32)&D_00361b20;\n asm("" : "+r"(table) : "m"(object[0x2b9]));\n object[0x2b9]=0;\n'
    text+=' asm("" : "+r"(object) : "r"(flags));\n' if marker==0 else ' asm("" : "+r"(object),"+r"(flags));\n'
    text+=' object[0]=table;\n object[0x163]=flags|1;\n *(u8*)(object+0x2ba)=0;\n}\n'
    sources[f'eight_hour_002c1aa0_v6_object_lifetime_{marker}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v6-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v6.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v6-variants.json'))
