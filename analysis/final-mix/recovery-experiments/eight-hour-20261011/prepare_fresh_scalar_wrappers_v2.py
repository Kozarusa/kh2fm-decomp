from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for profile in range(2):
 text=(base/f'eight_hour_002cba50_full_float_forward_{profile}.cpp').read_text()
 text=text.replace('{\n func_002cba88', '{\n register f32* fallback asm("$15")=&D_0037589c;\n asm("" : "+r"(fallback));\n func_002cba88').replace('D_0037589c,output','*fallback,output')
 sources[f'eight_hour_002cba50_v2_float_address_{profile}.cpp']=text
for profile in range(4):
 text=(base/'eight_hour_00304db0_double_classification_1.cpp').read_text().replace(' u32 high=', ' register u32 high asm("$2")=')
 if profile&1:text=text.replace(' u32 low=', ' asm("" : "+r"(high));\n u32 low=')
 if profile&2:text=text.replace(' return (0x7ff00000U-payload)>>31;', ' register u32 exponent asm("$14")=0x7ff00000U;\n asm("" : "+r"(exponent));\n return (exponent-payload)>>31;')
 sources[f'eight_hour_00304db0_v2_register_lifetimes_{profile}.cpp']=text
for profile in range(4):
 text='#include "../common/types.h"\nextern "C" f32 D_00376224;\nbool func_002eff58(f32* object)\n{\n register f32 first asm("$f1")=object[0x44];\n register f32* scale asm("$15")=&D_00376224;\n register f32 second asm("$f2")=object[0x45];\n'
 if profile&1:text+=' asm("" : "+f"(first),"+r"(scale),"+f"(second));\n'
 else:text+=' asm("" : "+r"(scale));\n'
 text+=' register f32 factor asm("$f0")=*scale;\n'
 if profile&2:text+=' asm("" : "+f"(factor),"+f"(first),"+f"(second));\n'
 text+=' first+=second;\n register f32 limit asm("$f3")=object[7];\n'
 if profile&2:text+=' asm("" : "+f"(first),"+f"(limit));\n'
 text+=' return first*factor<=limit;\n}\n'
 sources[f'eight_hour_002eff58_v2_float_registers_{profile}.cpp']=text
for profile in range(4):
 text='#include "../common/types.h"\nextern "C" void func_002fde18(u32,u32,u32);\ns32 func_0030df00()\n{\n'
 if profile&2:
  text+=' register u32 high asm("$2");\n asm("lui %0,0x36" : "=r"(high));\n register s32 disabled asm("$3");\n asm("addiu %0,$0,-1" : "=r"(disabled) : "r"(high));\n'
 else:text+=' register u32 high asm("$2")=0x360000;\n register s32 disabled asm("$3")=-1;\n'
 text+=' register u32 callback asm("$4")=0x1e40000;\n'
 if profile&1:text+=' asm("" : "+r"(high),"+r"(disabled),"+r"(callback));\n'
 else:text+=' asm("" : "+r"(high),"+r"(disabled));\n asm("" : "+r"(callback));\n'
 text+=' callback-=29080;\n *(s32*)(high+0x6180)=disabled;\n func_002fde18(callback,0,4);\n return 0;\n}\n'
 sources[f'eight_hour_0030df00_v2_constant_transport_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh-scalar-wrapper-v2-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh_scalar_wrappers_v2.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh-scalar-wrapper-v2-variants.json'))
