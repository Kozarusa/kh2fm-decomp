from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={};header='#include "../common/types.h"\n'
for profile in range(2):
 text=header+'extern "C" u32* func_001058e8();\nbool func_002424c0(u32 value)\n{\n u32* context=func_001058e8();\n u32 total=context[0x910]+value;\n'
 text+=(' return total<=999999U;\n' if profile else ' return total<1000000U;\n')+'}\n';sources[f'eight_hour_002424c0_context_unsigned_bound_{profile}.cpp']=text
 text=header+'extern "C" u8* func_001058e8();\nvoid func_00242980(s32* first,s32* second)\n{\n u8* context=func_001058e8();\n'
 text+=(' *second=*(s16*)(context+0x41a2);\n *first=*(s16*)(context+0x41a0);\n' if profile else ' *first=*(s16*)(context+0x41a0);\n *second=*(s16*)(context+0x41a2);\n')+'}\n';sources[f'eight_hour_00242980_context_signed_halfword_getter_{profile}.cpp']=text
 text=header+'extern "C" u8* func_001058e8();\nvoid func_002429c0(u32 first,u32 second)\n{\n u8* context=func_001058e8();\n'
 if profile:text+=' register u16* fields asm("$15")=(u16*)(context+0x41a0);\n asm("" : "+r"(fields));\n fields[0]=(u16)first;\n fields[1]=(u16)second;\n'
 else:text+=' *(u16*)(context+0x41a0)=(u16)first;\n *(u16*)(context+0x41a2)=(u16)second;\n'
 text+='}\n';sources[f'eight_hour_002429c0_context_halfword_setter_{profile}.cpp']=text
 for address,helper,value in [('0029e258','0028dac8',9),('0029e3a0','0028da70',8)]:
  text=header+f'extern "C" u32 func_002766d0();\nextern "C" void func_{helper}(u32,s32);\nvoid func_{address}(s32 index)\n{{\n u32 base=func_002766d0();\n'
  if profile:text+=' register s32 stride asm("$15")=408;\n asm("" : "+r"(stride));\n s32 offset=(index+1)*stride;\n'
  else:text+=' s32 offset=(index+1)*408;\n'
  text+=f' func_{helper}(base+offset+0x4398,{value});\n}}\n';sources[f'eight_hour_{address}_context_record_dispatch_{profile}.cpp']=text
 for address in ('00287720','00287760'):
  text=header+f'extern "C" void func_002878c8(u32*);\nextern "C" void func_0023f848(u32*);\nvoid func_{address}(u32* object)\n{{\n func_002878c8(object);\n u32* receiver=(u32*)object[0];\n typedef void (*Callback)(u32*);\n ((Callback)((u32*)*receiver)[5])(receiver);\n'
  text+=(' func_0023f848(object+3);\n' if not profile else ' u32 result=(u32)(object+3);\n asm("" : "+r"(result));\n func_0023f848((u32*)result);\n')+'}\n';sources[f'eight_hour_{address}_context_virtual_cleanup_{profile}.cpp']=text
 text=header+'extern "C" f32 D_0035db20[7];\nvoid func_002314c0(f32* input)\n{\n'
 if profile:text+=' register f32* output asm("$15")=D_0035db20;\n asm("" : "+r"(output));\n'
 else:text+=' f32* output=D_0035db20;\n'
 for source,destination in ((0,0),(1,1),(2,2),(3,4),(4,5),(5,6)):text+=f' output[{destination}]=input[{source}];\n'
 text+='}\n';sources[f'eight_hour_002314c0_context_float_vectors_{profile}.cpp']=text
 text=header+'extern "C" u32 D_0034aa70[5];\nextern "C" u8 D_0034aa40;\nvoid func_0015a6c8(u32* input)\n{\n'
 if profile:text+=' register u32* output asm("$12")=D_0034aa70;\n asm("" : "+r"(output));\n'
 else:text+=' u32* output=D_0034aa70;\n'
 for index in range(4):text+=f' output[{index}]=input[{index}];\n'
 text+=' D_0034aa40=1;\n output[4]=input[4];\n}\n';sources[f'eight_hour_0015a6c8_context_word_copy_flag_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'context-field-wrapper-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_context_field_wrappers.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','context-field-wrapper-variants.json'))
print(f'Prepared {len(sources)} native field wrappers.')
