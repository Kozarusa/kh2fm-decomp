from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for profile in range(2):
 text=(base/'eight_hour_002429c0_v2_direct_and_derived_fields_0.cpp').read_text()
 outputs='"+r"(first)'+(',"+r"(second)' if profile else '')
 text=text.replace(' *(u16*)(context+0x41a0)=(u16)first;',f' asm("" : {outputs} : "r"(fields));\n *(u16*)(context+0x41a0)=(u16)first;')
 sources[f'eight_hour_002429c0_v3_payload_address_dependency_{profile}.cpp']=text
for profile in range(4):
 if profile<3:
  text=(base/'eight_hour_0015a6c8_context_word_copy_flag_0.cpp').read_text().replace(' D_0034aa40=1;\n output[4]=input[4];',' u32 finalValue=input[4];\n D_0034aa40=1;\n output[4]=finalValue;')
  if profile:
   text=text.replace('extern "C" u8 D_0034aa40;','union WordByteFlag { u32 word; u8 bytes[4]; };\nextern "C" WordByteFlag D_0034aa40;').replace('D_0034aa40=1','D_0034aa40.bytes[0]=1')
  if profile==2:
   text=text.replace('extern "C" u32 D_0034aa70[5];', 'struct Configuration { u32 words[5]; };\nextern "C" Configuration D_0034aa70;').replace('func_0015a6c8(u32* input)', 'func_0015a6c8(Configuration* source)').replace(' u32* output=D_0034aa70;', ' u32* input=source->words;\n u32* output=D_0034aa70.words;')
 else:
  text='#include "../common/types.h"\nextern "C" u8 D_0034aa40;\nvoid func_0015a6c8(u32* input)\n{\n register u32 first asm("$13")=input[0];\n register u32 high asm("$14")=0x350000;\n asm("" : "+r"(first),"+r"(high));\n register u32* output asm("$12")=(u32*)(high-21904);\n asm("" : "+r"(output));\n *(u32*)(high-21904)=first;\n output[1]=input[1];\n output[2]=input[2];\n output[3]=input[3];\n u32 finalValue=input[4];\n D_0034aa40=1;\n output[4]=finalValue;\n}\n'
 sources[f'eight_hour_0015a6c8_v2_flag_alias_and_snapshot_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'context-fields-v3-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_context_fields_v3.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','context-fields-v3-variants.json'))
