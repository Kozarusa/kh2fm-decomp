from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(2):
 text=(base/'eight_hour_002429c0_v2_direct_and_derived_fields_0.cpp').read_text()
 qual='volatile ' if profile else ''
 text=text.replace(' *(u16*)(context+0x41a0)=(u16)first;',f' asm {qual}("sh %2,16800(%1)" : "=m"(*(u16*)(context+0x41a0)) : "r"(context),"r"(first),"r"(fields));')
 name=f'eight_hour_002429c0_v4_halfword_store_dependency_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
for profile in range(2):
 text=(base/'eight_hour_002b6b84_v3_frame_ABI_primitives_1.cpp').read_text()
 insert=' register s32 operation asm("$5");\n asm("addiu %0,$0,8" : "=r"(operation) : "r"(count));\n'
 text=text.replace(' register u64 result asm("$15")=func_002b6708(count,8,payload[0]);', insert+' register u64 result asm("$15")=func_002b6708(count,operation,payload[0]);')
 if profile:text=text.replace('asm("addiu %0,$0,8"','asm volatile("addiu %0,$0,8"')
 name=f'eight_hour_002b6b84_v4_argument_constant_dependencies_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'context-and-frame-v4-variants.json').write_text(json.dumps(names))
(base/'probe_context_and_frame_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','context-and-frame-v4-variants.json'))
