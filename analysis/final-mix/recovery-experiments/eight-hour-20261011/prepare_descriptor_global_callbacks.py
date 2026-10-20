from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for row in json.loads((base/'descriptor-global-callback-census.json').read_text())['pending']:
 address=row['address'];descriptor=row['descriptor'];global_address=row['global']
 for profile in range(4):
  global_type='u32*' if profile&1 else 'u32'
  text='#include "../common/types.h"\n'+f'extern "C" u8 D_{descriptor};\nextern "C" {global_type} D_{global_address};\nvoid func_{address}(u32* object)\n{{\n'
  if profile&2:text+=f' register u32 table asm("$15")=(u32)&D_{descriptor};\n asm("" : "+r"(table));\n *object=table;\n'
  else:text+=f' *object=(u32)&D_{descriptor};\n'
  if row['receiver_field'] is None:text+=f' u32* receiver=(u32*)D_{global_address};\n'
  else:text+=f' u32* control=(u32*)D_{global_address};\n u32* receiver=(u32*)control[{row["receiver_field"]//4}];\n'
  text+=f' typedef void (*Callback)(u32*,u32*);\n ((Callback)((u32*)*receiver)[{row["callback_slot"]//4}])(receiver,object);\n}}\n'
  sources[f'eight_hour_{address}_descriptor_global_callback_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'descriptor-global-callback-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_descriptor_global_callbacks.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','descriptor-global-callback-variants.json'))
print(f'Prepared {len(sources)} complete descriptor/global callback proposals.')
