from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for address in ('0017c8f0','001b6f48'):
 for profile in range(4):
  text=(base/f'eight_hour_{address}_v2_saved_output_dependency_{1 if not profile&2 else 3}.cpp').read_text()
  text=text.replace(' return output;',' return saved;')
  if profile&1:text=text.replace('output,second,third','saved,second,third')
  sources[f'eight_hour_{address}_v3_saved_output_return_{profile}.cpp']=text
for profile in range(4):
 text=(base/'eight_hour_001375f0_float_payload_constructor_1.cpp').read_text()
 if profile&1:
  text=text.replace('f32,u32*,u64,u64,u64','f32,u64,u64,u64,u64').replace('func_001375f0(u32* object,','func_001375f0(u64 object,').replace(' object[0x146]=0;',' *(u32*)((u32)object+1304)=0;')
 if profile&2:
  old=' register f32* scale asm("$15")=&D_0036ac9c;\n asm("" : "+r"(scale));'
  new=' register u32 high asm("$15")=0x370000;\n asm("" : "+r"(high));\n register f32* scale asm("$15");\n asm("addiu %0,%1,-21348" : "=r"(scale) : "r"(high));'
  assert old in text;text=text.replace(old,new)
 sources[f'eight_hour_001375f0_v3_object_carrier_and_address_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh60-64-v3-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh60_64_v3.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh60-64-v3-variants.json'))
