from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('002d96d8','002d9730'):
 for profile in range(2):
  text=(base/f'eight_hour_{address}_v2_observed_store_groups_{profile}.cpp').read_text()
  zero=' *(f32*)(object+0x2fd)=0.0f;' if profile else ' object[0x2fd]=0;'
  byte=' *(u8*)(object+0x301)=1;';assert zero+'\n'+byte in text
  text=text.replace(zero+'\n'+byte,byte+'\n'+zero)
  name=f'eight_hour_{address}_v3_adjacent_store_order_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'byte-float-constructor-v3-variants.json').write_text(json.dumps(names))
(base/'probe_byte_float_constructors_v3.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','byte-float-constructor-v3-variants.json'))
