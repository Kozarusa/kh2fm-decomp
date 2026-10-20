"""Retain observed frame setup as narrow ABI primitives; compile the call and value flow normally."""
from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('002b7f84','002b6b84'):
 for profile in range(4):
  payload=address=='002b6b84';count=2 if payload else 1;operation=8 if payload else 49
  text='#include "../common/types.h"\nextern "C" u64 func_002b6708(s32,s32,...);\n'+f'u64 func_{address}({"u32 input" if payload else ""})\n{{\n'
  if payload:text+=' u8 argumentArea[16];\n asm volatile("" : "=m"(argumentArea));\n'
  text+=' register void* frame asm("$30");\n asm volatile("daddu %0,$29,$0" : "=r"(frame));\n'
  if payload:text+=' volatile u32* payload=(volatile u32*)frame;\n payload[0]=input;\n'
  if profile&1:
   deps='"m"(payload[0])' if payload else '"r"(frame)'
   text+=f' register s32 count asm("$4");\n asm("addiu %0,$0,{count}" : "=r"(count) : {deps});\n'
   count_arg='count'
  else:count_arg=str(count)
  expression=f'func_002b6708({count_arg},{operation}{",payload[0]" if payload else ""})'
  text+=f' register u64 result asm("$15")={expression};\n asm("" : "+r"(result));\n register u64 returned asm("$2")=result;\n asm("" : "+r"(returned));\n'
  qualifier='volatile ' if profile&2 else ''
  text+=f' asm {qualifier}("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));\n return returned;\n}}\n'
  name=f'eight_hour_{address}_v3_frame_ABI_primitives_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'frame-pointer-v3-variants.json').write_text(json.dumps(names))
(base/'probe_frame_pointer_v3.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','frame-pointer-v3-variants.json'))
