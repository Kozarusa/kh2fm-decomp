from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(6):
 text=(base/'eight_hour_00137c50_fresh_initialization_0.cpp').read_text()
 marker=' asm volatile("" : '
 if profile&1:marker+='"=m"(fields[0xa71])'
 marker+=' : "m"(fields[12]),"m"(fields[13]),"m"(fields[8]),"m"(fields[0xa70]));\n'
 text=text.replace(' fields[0xa71]=0;',marker+' fields[0xa71]=0;')
 if profile>=2:text=text.replace(' fields[0xa70]=1;\n fields[8]=1;',' fields[8]=1;\n fields[0xa70]=1;')
 if profile>=4:text=text.replace(' fields[12]=0;\n fields[13]=0;',' fields[13]=0;\n fields[12]=0;')
 name=f'eight_hour_00137c50_v5_store_commit_dependency_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'initialization-v5-variants.json').write_text(json.dumps(names))
(base/'probe_initialization_v5.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','initialization-v5-variants.json'))
