"""Test observed frame-pointer wrappers without changing pinned compiler flags."""
from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('002b7f84','002b6b84'):
 for profile in range(4):
  payload=address=='002b6b84'
  text='#include "../common/types.h"\nextern "C" u64 func_002b6708(s32,s32,...);\n'+f'u64 func_{address}({"u32 input" if payload else ""})\n{{\n'
  if payload:text+=' volatile u32 payload=input;\n'
  text+=' void* frame=__builtin_frame_address(0);\n'
  if profile&1:text+=' asm volatile("" : : "r"(frame));\n'
  expression='func_002b6708(2,8,payload)' if payload else 'func_002b6708(1,49)'
  text+=f' register u64 result asm("$15")={expression};\n asm("" : "+r"(result));\n'
  if profile&2:text+=' register u64 returned asm("$2")=result;\n asm("" : "+r"(returned) : "r"(frame));\n return returned;\n'
  else:text+=' asm volatile("" : : "r"(frame));\n return result;\n'
  text+='}\n';name=f'eight_hour_{address}_frame_pointer_control_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'frame-pointer-control-variants.json').write_text(json.dumps(names))
(base/'probe_frame_pointer_controls.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','frame-pointer-control-variants.json'))
