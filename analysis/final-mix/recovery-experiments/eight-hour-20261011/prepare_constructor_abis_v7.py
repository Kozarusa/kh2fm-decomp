from pathlib import Path
import json
base=Path(__file__).resolve().parent
sources={}
for address in ('0014ba20','0014ba90'):
    text=(base/f'eight_hour_{address}_v5_bound_constants_1.cpp').read_text()
    text=text.replace('*(u64*)(object+0x42)=fourteen;', 'register u32 table asm("$15")=0x00350000;\n asm("" : "+r"(table));\n asm volatile("sd %1,%0" : "=m"(*(u64*)(object+0x42)) : "r"(fourteen));')
    text=text.replace('*(u64*)(object+0x46)=sixtyfour;', 'asm volatile("addiu %0,%0,-25176" : "+r"(table) : "m"(*(u64*)(object+0x40)));\n *(u64*)(object+0x46)=sixtyfour;').replace('*object=(u32)&D_00349da8;', '*object=table;')
    sources[f'eight_hour_{address}_v7_precise_first_group.cpp']=text
for marker in (0,1):
    text='#include "../common/types.h"\nextern "C" u8 D_00361b20;\nextern "C" void func_002be770(u32*,u64,u64);\nvoid func_002c1aa0(u32* object,u64 second,u64 third)\n{\n func_002be770(object,second,third);\n register u32 flags asm("$14")=object[0x163];\n register u32 table asm("$15")=(u32)&D_00361b20;\n asm("" : "+r"(table) : "m"(object[0x2b9]));\n'
    if marker:
        text+=' asm volatile("sw $0,%0" : "=m"(object[0x2b9]),"+r"(flags) : "m"(*(u8*)(object+0x2ba)));\n'
    else:
        text+=' asm volatile("sw $0,%0" : "=m"(object[0x2b9]) : "m"(*(u8*)(object+0x2ba)));\n'
    text+=' object[0]=table;\n object[0x163]=flags|1;\n *(u8*)(object+0x2ba)=0;\n}\n'
    sources[f'eight_hour_002c1aa0_v7_precise_clear_{marker}.cpp']=text
for name,text in sources.items():
    (base/name).write_text(text)
(base/'constructor-abi-v7-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_constructor_abis_v7.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','constructor-abi-v7-variants.json'))
