from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for address in ('0017c8f0','001b6f48'):
 for profile in range(2):
  text=(base/f'eight_hour_{address}_full_float_pair_forward_1.cpp').read_text()
  text=text.replace('{\n register f32* firstAddress','{\n u32* preservedOutput=output;\n register f32* firstAddress')
  text=text.replace(' asm("" : "+r"(firstAddress));',' asm("" : "+r"(firstAddress),"+r"(output));')
  text=text.replace(' return output;',' return preservedOutput;')
  if not profile:text=text.replace(' asm("" : "+f"(first));\n','')
  name=f'eight_hour_{address}_v4_callee_copy_and_preserved_return_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'float-pair-v4-variants.json').write_text(json.dumps(names))
(base/'probe_float_pair_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','float-pair-v4-variants.json'))
