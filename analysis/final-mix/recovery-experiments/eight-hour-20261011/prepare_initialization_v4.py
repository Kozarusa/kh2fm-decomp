from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(8):
 text='#include "../common/types.h"\nextern "C" void func_001391c8(u32*,u32,u32);\nvoid func_00137c50(u32* object)\n{\n u32* fields=object;\n fields[0xa72]=0;\n register u32 one asm("$14")=1;\n'
 text+=' asm("" : "+r"(one)'+(' : "m"(fields[0xa72])' if profile&1 else '')+');\n fields[0xa70]=one;\n'
 if profile&2:text+=' asm("" : "+r"(one) : "m"(fields[0xa70]));\n'
 text+=' fields[8]=one;\n fields[12]=0;\n fields[13]=0;\n'
 qualifier='volatile ' if profile&4 else ''
 text+=f' asm {qualifier}("" : "+r"(fields) : "m"(fields[12]),"m"(fields[13]),"m"(fields[8]),"m"(fields[0xa70]));\n fields[0xa71]=0;\n func_001391c8(object,0x2b5c,0);\n}}\n'
 name=f'eight_hour_00137c50_v4_precise_field_dependencies_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'initialization-v4-variants.json').write_text(json.dumps(names))
(base/'probe_initialization_v4.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','initialization-v4-variants.json'))
