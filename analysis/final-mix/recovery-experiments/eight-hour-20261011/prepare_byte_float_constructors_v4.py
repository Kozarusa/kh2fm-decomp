from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('002d96d8','002d9730'):
 for profile in range(4):
  text=(base/f'eight_hour_{address}_v2_observed_store_groups_0.cpp').read_text()
  text=text.replace('object+0x301','object+BYTE_SWAP').replace('object+0x2ff','object+0x301').replace('object+BYTE_SWAP','object+0x2ff')
  text=text.replace(' object[0x2fc]=0;',' register u32 one asm("$14")=1;\n asm("" : "+r"(one));\n object[0x2fc]=0;')
  text=text.replace('*(u8*)(object+0x301)=1','*(u8*)(object+0x301)=one').replace('*(u8*)(object+0x2ff)=1','*(u8*)(object+0x2ff)=one')
  qualifier='volatile ' if profile&1 else ''
  deps='"m"(object[0x2fd])'+(',"m"(*object)' if profile&2 else '')
  text=text.replace(' *(u8*)(object+0x2ff)=one;',f' asm {qualifier}("" : "+r"(one) : {deps});\n *(u8*)(object+0x2ff)=one;')
  name=f'eight_hour_{address}_v4_byte_value_lifetime_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'byte-float-constructor-v4-variants.json').write_text(json.dumps(names))
(base/'probe_byte_float_constructors_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','byte-float-constructor-v4-variants.json'))
