from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for profile in range(4):
 if profile&2:
  text='#include "../common/types.h"\nunion WordHalfCell { s32 word; s16 halves[2]; };\nextern "C" WordHalfCell* func_001058e8();\nvoid func_00242980(WordHalfCell* first,WordHalfCell* second)\n{\n WordHalfCell* context=func_001058e8();\n first->word=context[0x1068].halves[0];\n second->word=context[0x1068].halves[1];\n}\n'
  if profile&1:text=text.replace('first->word=', '((volatile WordHalfCell*)first)->word=').replace('second->word=', '((volatile WordHalfCell*)second)->word=')
 else:
  text=(base/'eight_hour_00242980_context_signed_halfword_getter_0.cpp').read_text().replace('*(s16*)','*(volatile s16*)')
  if profile&1:text=text.replace(' *first=', ' *(volatile s32*)first=').replace(' *second=',' *(volatile s32*)second=')
 sources[f'eight_hour_00242980_v2_halfword_aliasing_{profile}.cpp']=text
for profile in range(2):
 text=(base/'eight_hour_002429c0_context_halfword_setter_1.cpp').read_text()
 text=text.replace(' fields[0]=(u16)first;', ' *(u16*)(context+0x41a0)=(u16)first;')
 if profile:text=text.replace(' asm("" : "+r"(fields));',' asm("" : "+r"(fields) : "r"(first),"r"(second));')
 sources[f'eight_hour_002429c0_v2_direct_and_derived_fields_{profile}.cpp']=text
for address in ('00287720','00287760'):
 text=(base/f'eight_hour_{address}_context_virtual_cleanup_0.cpp').read_text()
 text=text.replace('void func_0023f848(u32*);','u32 func_0023f848(u32*);').replace(' func_0023f848(object+3);',' u32 result=func_0023f848(object+3);\n asm("" : : "r"(result));')
 sources[f'eight_hour_{address}_v2_callback_result_use.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'context-fields-v2-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_context_fields_v2.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','context-fields-v2-variants.json'))
