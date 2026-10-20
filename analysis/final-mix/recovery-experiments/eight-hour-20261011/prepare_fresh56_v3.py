from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for profile in range(8):
 text=(base/'eight_hour_00137c50_fresh_initialization_0.cpp').read_text()
 start=text.index(' fields[0xa72]');end=text.index(' func_001391c8',start)
 zeros=[' fields[12]=0;',' fields[13]=0;']
 if profile&4:zeros.reverse()
 ones=[' fields[0xa70]=1;',' fields[8]=1;']
 if profile&2:ones.reverse()
 if profile&1:stores=[' fields[0xa71]=0;']+ones+zeros+[' fields[0xa72]=0;']
 else:stores=[' fields[0xa72]=0;']+ones+zeros+[' fields[0xa71]=0;']
 text=text[:start]+'\n'.join(stores)+'\n'+text[end:]
 sources[f'eight_hour_00137c50_v3_independent_store_order_{profile}.cpp']=text
for address,delta in [('00262730',2504),('0027d450',0)]:
 for profile in range(4):
  text=(base/f'eight_hour_{address}_fresh_three_calls_1.cpp').read_text()
  old=f' u32 object=func_00257770(){"+2504" if delta else ""};'
  qualifier='volatile ' if profile&1 else ''
  reg='u64' if profile&2 else 'u32'
  new=f' register {reg} object asm("$16");\n asm {qualifier}("" : "=r"(object));\n object=func_00257770(){"+2504" if delta else ""};'
  assert old in text;text=text.replace(old,new)
  sources[f'eight_hour_{address}_v3_pre_call_register_definition_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh56-v3-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh56_v3.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh56-v3-variants.json'))
