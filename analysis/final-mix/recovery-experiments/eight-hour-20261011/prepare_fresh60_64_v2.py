from pathlib import Path
import json,re
base=Path(__file__).resolve().parent;sources={}
text=(base/'eight_hour_00132270_scalar_field_initialization_1.cpp').read_text()
mapping={2:3,3:4,4:5,5:7,7:8,8:2}
text=re.sub(r'object\[(2|3|4|5|7|8)\]=0;',lambda m:f'object[{mapping[int(m[1])]}]=0;',text)
sources['eight_hour_00132270_v2_zero_store_rotation.cpp']=text
for profile in range(4):
 text=(base/'eight_hour_001375f0_float_payload_constructor_1.cpp').read_text()
 deps=['"r"(second)','"r"(third)','"r"(second),"r"(third)','"m"(object[0x146])'][profile]
 text=text.replace(' asm("" : "+r"(scale));',f' asm("" : "+r"(scale) : {deps});')
 sources[f'eight_hour_001375f0_v2_float_address_lifetimes_{profile}.cpp']=text
for address in ('0017c8f0','001b6f48'):
 for profile in range(4):
  text=(base/f'eight_hour_{address}_full_float_pair_forward_1.cpp').read_text()
  declaration=' register u32* saved asm("$16")=output;' if profile&1 else ' u32* saved=output;'
  text=text.replace(' asm("" : "+r"(firstAddress));',declaration+'\n asm("" : "+r"(firstAddress) : "r"(saved));')
  if not profile&2:text=text.replace(' asm("" : "+f"(first));\n','')
  sources[f'eight_hour_{address}_v2_saved_output_dependency_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh60-64-v2-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh60_64_v2.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh60-64-v2-variants.json'))
