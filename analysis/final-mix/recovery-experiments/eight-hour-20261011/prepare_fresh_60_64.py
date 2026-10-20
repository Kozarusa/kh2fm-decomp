from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={};header='#include "../common/types.h"\n'
for address,slot in [('00123d90',24),('00124100',44)]:
 for profile in range(4):
  result='u64' if profile&1 else 'void';receiver_type='u64' if profile&2 else 'u32*'
  text=header+f'extern "C" {receiver_type} func_00124748(u32*,s32);\n{result} func_{address}(u32* object,u64 payload)\n{{\n {receiver_type} receiver=func_00124748(object,0);\n typedef {result} (*Callback)({receiver_type},u64);\n'+(' return ' if profile&1 else ' ')+f'((Callback)((u32*)*(u32*)receiver)[{slot//4}])(receiver,payload);\n}}\n'
  sources[f'eight_hour_{address}_virtual_result_wrapper_{profile}.cpp']=text
for profile in range(2):
 text=header+'extern "C" u8 D_00347c00;\nextern "C" f32 D_0036ac28;\nvoid func_00132270(u32* object,u32 payload)\n{\n object[1]=payload;\n object[2]=0;\n object[3]=0;\n'
 text+=(' register f32* scale asm("$15")=&D_0036ac28;\n asm("" : "+r"(scale));\n *(f32*)(object+6)=*scale;\n' if profile else ' *(f32*)(object+6)=D_0036ac28;\n')
 text+=' object[4]=0;\n *object=(u32)&D_00347c00;\n object[5]=0;\n object[7]=0;\n object[8]=0;\n}\n';sources[f'eight_hour_00132270_scalar_field_initialization_{profile}.cpp']=text
 text=header+'extern "C" f32 D_0036ac9c;\nextern "C" void func_001374c8(f32,u32*,u64,u64,u64);\nvoid func_001375f0(u32* object,u64 second,u64 third)\n{\n'
 text+=(' register f32* scale asm("$15")=&D_0036ac9c;\n asm("" : "+r"(scale));\n func_001374c8(*scale,object,79,second,third);\n' if profile else ' func_001374c8(D_0036ac9c,object,79,second,third);\n')+' object[0x146]=0;\n}\n';sources[f'eight_hour_001375f0_float_payload_constructor_{profile}.cpp']=text
 text=header+'extern "C" f32 func_0017ce10(f32);\nvoid func_0013f608(f32* object)\n{\n'
 text+=(' object[40]=object[12];\n object[41]=object[13];\n' if profile else ' object[41]=object[13];\n object[40]=object[12];\n')+' object[41]=func_0017ce10(object[13]);\n}\n';sources[f'eight_hour_0013f608_float_field_transform_{profile}.cpp']=text
 args=','.join(['u64']*5);params=','.join(f'u64 p{i}' for i in range(5));actual=','.join(f'p{i}' for i in range(5))
 sources[f'eight_hour_0014f688_five_payload_forward_{profile}.cpp']=header+f'extern "C" u32 D_0034a428;\nextern "C" void func_00150dc0(u32,{args});\nvoid func_0014f688({params})\n{{\n func_00150dc0(D_0034a428,{actual});\n}}\n'
 sources[f'eight_hour_00153310_seven_argument_forward_{profile}.cpp']=header+f'extern "C" u32 D_0034a6f0;\nextern "C" void func_0031cc30(u32,u32,{args});\nvoid func_00153310({params})\n{{\n func_0031cc30(D_0034a6f0+24,1,{actual});\n}}\n'
 text=header+'extern "C" f32 D_0034aa44;\nextern "C" f32 func_0015a098();\nextern "C" f32 func_0017ce10(f32);\nvoid func_0015a118(f32* object)\n{\n f32 value=func_0015a098();\n'
 if profile:text+=' register f32 result asm("$f0")=value+D_0034aa44;\n asm("" : "+f"(result));\n object[20]=func_0017ce10(result);\n'
 else:text+=' object[20]=func_0017ce10(value+D_0034aa44);\n'
 text+='}\n';sources[f'eight_hour_0015a118_float_result_transform_{profile}.cpp']=text
 for address,first,second in [('0017c8f0','0036c524','0036c528'),('001b6f48','0036dac4','0036dac8')]:
  text=header+f'extern "C" f32 D_{first};\nextern "C" f32 D_{second};\nextern "C" u32* func_0017c870(f32,f32,u32*,u64,u64);\nu32* func_{address}(u32* output,u64 second,u64 third)\n{{\n'
  if profile:
   text+=f' register f32* firstAddress asm("$15")=&D_{first};\n asm("" : "+r"(firstAddress));\n register f32 first asm("$f12")=*firstAddress;\n asm("" : "+f"(first));\n register f32* secondAddress asm("$15")=&D_{second};\n asm("" : "+r"(secondAddress));\n func_0017c870(first,*secondAddress,output,second,third);\n'
  else:text+=f' func_0017c870(D_{first},D_{second},output,second,third);\n'
  text+=' return output;\n}\n';sources[f'eight_hour_{address}_full_float_pair_forward_{profile}.cpp']=text
 text=header+'void func_001d4dc0(u32* object,u32 second,u32 third,u32 fourth)\n{\n object[0x8e]=second;\n object[6]=9999;\n object[0x8f]=third;\n object[0x90]=fourth;\n object[11]=0;\n typedef void (*Callback)(u32*);\n ((Callback)((u32*)*object)[1])(object);\n}\n'
 if profile:text=text.replace('object[6]=9999;', 'register u32 sentinel asm("$14")=9999;\n asm("" : "+r"(sentinel));\n object[6]=sentinel;')
 sources[f'eight_hour_001d4dc0_virtual_field_initialization_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh60-64-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh60_64.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh60-64-variants.json'))
print(f'Prepared {len(sources)} complete 60/64-byte proposals.')
