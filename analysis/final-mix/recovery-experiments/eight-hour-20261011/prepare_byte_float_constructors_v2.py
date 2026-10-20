from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('002d96d8','002d9730'):
 for profile in range(2):
  text=(base/f'eight_hour_{address}_byte_float_constructor_{profile}.cpp').read_text()
  text=text.replace(' object[0x326]=0;\n','').replace(' object[0x325]=0;',' object[0x325]=0;\n object[0x326]=0;')
  text=text.replace('object+0x301','object+BYTE_SWAP').replace('object+0x2ff','object+0x301').replace('object+BYTE_SWAP','object+0x2ff')
  name=f'eight_hour_{address}_v2_observed_store_groups_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'byte-float-constructor-v2-variants.json').write_text(json.dumps(names))
(base/'probe_byte_float_constructors_v2.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','byte-float-constructor-v2-variants.json'))
