from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={};header='#include "../common/types.h"\n'
for profile in range(4):
 text=header+'extern "C" f32 D_0036b210;\nvoid func_0014f030(f32 start,f32 end,f32 duration,f32* output)\n{\n'
 if profile&1:text+=' f32 difference=end-start;\n'
 text+=' if(duration==0.0f)\n {\n'
 if profile&2:text+='  register f32* fallback asm("$15")=&D_0036b210;\n  asm("" : "+r"(fallback));\n  duration=*fallback;\n'
 else:text+='  duration=D_0036b210;\n'
 text+=' }\n'
 if not profile&1:text+=' f32 difference=end-start;\n'
 text+=' output[0]=start;\n output[2]=end;\n output[1]=difference/duration;\n}\n'
 sources[f'eight_hour_0014f030_scalar_interpolation_{profile}.cpp']=text
for profile in range(2):
 payload='u64' if profile else 'u32*'
 sources[f'eight_hour_002cba50_full_float_forward_{profile}.cpp']=header+f'extern "C" f32 D_0037589c;\nextern "C" {payload} func_002cba88(f32,f32,{payload},u32*,u32*,u32*);\n{payload} func_002cba50({payload} output,u32* record,u32* first,u32* second)\n{{\n func_002cba88(*(f32*)(record+9),D_0037589c,output,record,first,second);\n return output;\n}}\n'
 sources[f'eight_hour_002eff58_scalar_predicate_{profile}.cpp']=header+'extern "C" f32 D_00376224;\n'+f'{"u32" if profile else "bool"} func_002eff58(f32* object)\n{{\n return (object[0x44]+object[0x45])*D_00376224<=object[7];\n}}\n'
 sources[f'eight_hour_00304db0_double_classification_{profile}.cpp']=header+'u32 func_00304db0(u64 bits)\n{\n u32 high=(u32)(bits>>32);\n u32 low=(u32)bits;\n'+(' u32 payload=(high&0x7fffffff)|((low|(0U-low))>>31);\n return (0x7ff00000U-payload)>>31;\n' if profile else ' return (0x7ff00000U-((high&0x7fffffff)|((low|(0U-low))>>31)))>>31;\n')+'}\n'
for profile in range(3):
 text=header+'extern "C" s32 D_00366180;\nextern "C" void func_002fde18(u32,u32,u32);\ns32 func_0030df00()\n{\n'
 if profile:
  text+=' register u32 high asm("$2")=0x360000;\n asm("" : "+r"(high));\n *(s32*)(high+0x6180)=-1;\n register u32 callback asm("$4")=0x1e40000;\n'
  if profile==2:text+=' asm("addiu %0,%0,-29080" : "+r"(callback) : "m"(*(s32*)(high+0x6180)));\n'
  else:text+=' asm("" : "+r"(callback));\n callback-=29080;\n'
  text+=' func_002fde18(callback,0,4);\n'
 else:text+=' D_00366180=-1;\n func_002fde18(0x1e38e68,0,4);\n'
 text+=' return 0;\n}\n';sources[f'eight_hour_0030df00_sdk_reset_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh-scalar-wrapper-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh_scalar_wrappers.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh-scalar-wrapper-variants.json'))
print(f'Prepared {len(sources)} scalar and complete-ABI proposals.')
