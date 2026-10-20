from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(4):
 text=(base/'eight_hour_001375f0_float_payload_constructor_1.cpp').read_text()
 third='u32' if profile&1 else 'u64';identifier='s32' if profile&2 else 'u64'
 text=text.replace('func_001374c8(f32,u32*,u64,u64,u64)',f'func_001374c8(f32,u32*,{identifier},u64,{third})')
 if profile&1:text=text.replace('u64 second,u64 third','u64 second,u32 third')
 name=f'eight_hour_001375f0_v4_helper_word_widths_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'float-payload-constructor-v4-variants.json').write_text(json.dumps(names))
(base/'probe_float_payload_constructor_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','float-payload-constructor-v4-variants.json'))
