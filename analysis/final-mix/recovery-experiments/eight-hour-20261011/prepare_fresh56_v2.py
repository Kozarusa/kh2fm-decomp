from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for address in ('0010c7f0','0011c4b0','0015b4c0'):
 for profile in range(2):
  text=(base/f'eight_hour_{address}_fresh_virtual_{profile}.cpp').read_text();assert '(*(u32**)*receiver)' in text
  text=text.replace('(*(u32**)*receiver)','((u32*)*receiver)')
  sources[f'eight_hour_{address}_v2_correct_virtual_table_{profile}.cpp']=text
for profile in range(4):
 text=(base/f'eight_hour_0011f238_fresh_virtual_index_{profile}.cpp').read_text();assert '(*(u32**)*object)' in text
 text=text.replace('(*(u32**)*object)','((u32*)*object)')
 sources[f'eight_hour_0011f238_v2_correct_virtual_table_{profile}.cpp']=text
for address in ('00262730','0027d450'):
 for profile in range(4):
  text=(base/f'eight_hour_{address}_fresh_three_calls_1.cpp').read_text()
  if profile==0:text=text.replace('{\n u32 object','{\n asm volatile("" : : : "$16");\n u32 object')
  elif profile==1:text=text.replace(' u32 object=func_00257770()', ' register u32 object asm("$16")=func_00257770()').replace(' func_00139d78(object);',' asm("" : "+r"(object));\n func_00139d78(object);')
  elif profile==2:text=text.replace(' u32 object=func_00257770()', ' register u32 object asm("$16")=func_00257770()').replace(' func_00139d78(object);',' asm volatile("" : "+r"(object));\n func_00139d78(object);')
  else:text=text.replace('{\n u32 object','{\n asm volatile("" : : : "$16","memory");\n u32 object')
  sources[f'eight_hour_{address}_v2_prologue_lifetime_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh56-v2-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh56_v2.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh56-v2-variants.json'))
print('Corrected table dereference in ten new proposals; eight prologue probes.')
