from pathlib import Path
import json
base=Path(__file__).resolve().parent;sources={}
for profile in range(2):
 text=(base/'eight_hour_002cba50_v2_float_address_0.cpp').read_text()
 insertion=' register f32 factor asm("$f13")=*fallback;\n asm("" : "+r"(record) : "f"(factor));\n'
 if profile:text=text.replace(' asm("" : "+r"(fallback));',' asm("" : "+r"(fallback));\n'+insertion.replace('asm(""','asm volatile(""'))
 else:text=text.replace(' asm("" : "+r"(fallback));',' asm("" : "+r"(fallback));\n'+insertion)
 text=text.replace('*fallback,output','factor,output')
 sources[f'eight_hour_002cba50_v3_float_load_dependency_{profile}.cpp']=text
for profile in range(4):
 text=(base/'eight_hour_002eff58_v2_float_registers_0.cpp').read_text()
 insertion=' asm("" : "+f"(first) : "f"(factor)'+(',"f"(second)' if profile&1 else '')+');\n'
 text=text.replace(' first+=second;',insertion+' first+=second;')
 text=text.replace(' return first*factor<=limit;', ' first*=factor;\n'+(' asm("" : "+f"(first) : "f"(limit));\n' if profile&2 else ' asm("" : "+f"(first));\n')+' return first<=limit;')
 sources[f'eight_hour_002eff58_v3_float_value_lifetimes_{profile}.cpp']=text
for profile in range(2):
 text=(base/'eight_hour_00304db0_double_classification_1.cpp').read_text()
 if profile:text=text.replace(' u32 payload=', ' asm("" : "+r"(high) : "r"(bits));\n u32 payload=')
 else:text=text.replace(' return (0x7ff00000U-payload)>>31;', ' asm("" : "+r"(payload) : "r"(bits));\n return (0x7ff00000U-payload)>>31;')
 sources[f'eight_hour_00304db0_v3_input_lifetime_{profile}.cpp']=text
for profile in range(4):
 text=(base/'eight_hour_0030df00_v2_constant_transport_0.cpp').read_text()
 if profile&1:text=text.replace(' asm("" : "+r"(callback));', ' asm("lui %0,0x1e4" : "=r"(callback) : "r"(high),"r"(disabled));')
 deps='"r"(callback)' if not profile&2 else '"r"(callback),"r"(high)'
 text=text.replace(' *(s32*)(high+0x6180)=disabled;', f' asm("" : "+r"(disabled) : {deps});\n *(s32*)(high+0x6180)=disabled;')
 sources[f'eight_hour_0030df00_v3_store_value_dependency_{profile}.cpp']=text
for name,text in sources.items():
 assert not(base/name).exists();(base/name).write_text(text)
(base/'fresh-scalar-wrapper-v3-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_fresh_scalar_wrappers_v3.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','fresh-scalar-wrapper-v3-variants.json'))
