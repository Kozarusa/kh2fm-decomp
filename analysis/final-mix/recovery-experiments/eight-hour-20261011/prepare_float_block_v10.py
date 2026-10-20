from pathlib import Path
import json
base=Path(__file__).resolve().parent
names=[]
for profile in range(8):
 text=(base/'eight_hour_002d49c0_v3_block_dependencies_1.cpp').read_text()
 start=text.index(' register f32* block');text=text[:start]
 text+=' register f32* block asm("$14");\n asm("addiu %0,%1,3072" : "=r"(block) : "r"(object),"m"(*object));\n register f32 copied asm("$f1");\n'
 qual='volatile ' if profile&1 else ''
 text+=f' asm {qual}("lwc1 %0,%2" : "=f"(copied) : "r"(block),"m"(*(f32*)(object+0x2fc)));\n'
 text+=' register u32 high asm("$15");\n asm("lui %0,0x37" : "=r"(high) : "f"(copied));\n register f32* scale asm("$15")=(f32*)(high+0x5af0);\n asm("" : "+r"(scale));\n'
 if profile&2:text+=' asm("" : "+r"(block),"+f"(copied) : "r"(scale));\n'
 text+=' ((volatile f32*)block)[3]=copied;\n ((volatile f32*)block)[1]=copied;\n ((volatile f32*)block)[2]=copied;\n register f32 value asm("$f0")=*(volatile f32*)scale;\n'
 qualifier='volatile ' if profile&4 else ''
 text+=f' *({qualifier}u32*)(object+0x30d)=0;\n *({qualifier}f32*)(object+0x304)=value;\n *({qualifier}f32*)(object+0x300)=copied;\n'
 for index in (0x305,0x306,0x307,0x30c):text+=f' *({qualifier}u32*)(object+{index})=0;\n'
 text+='}\n'
 name=f'eight_hour_002d49c0_v10_float_memory_order_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'float-block-v10-variants.json').write_text(json.dumps(names))
(base/'probe_float_block_v10.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','float-block-v10-variants.json'))
