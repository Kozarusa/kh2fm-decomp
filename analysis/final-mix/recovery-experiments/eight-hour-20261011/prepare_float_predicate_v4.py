from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(2):
 text=(base/'eight_hour_002eff58_v2_float_registers_0.cpp').read_text()
 text=text.replace(' first+=second;',' asm("add.s %0,%0,%1" : "+f"(first) : "f"(second),"f"(factor));')
 if profile:text=text.replace(' register f32 limit asm("$f3")=object[7];',' register f32 limit asm("$f3")=object[7];\n asm("" : "+f"(limit));')
 text=text.replace(' return first*factor<=limit;', ' asm("mul.s %0,%0,%1" : "+f"(first) : "f"(factor),"f"(limit));\n return first<=limit;')
 name=f'eight_hour_002eff58_v4_float_operation_dependencies_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'float-predicate-v4-variants.json').write_text(json.dumps(names))
(base/'probe_float_predicate_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','float-predicate-v4-variants.json'))
