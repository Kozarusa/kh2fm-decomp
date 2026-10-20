from pathlib import Path
import json
base=Path(__file__).resolve().parent;names=[]
for profile in range(4):
 text='#include "../common/types.h"\nextern "C" f32 D_00376224;\nbool func_002eff58(f32* object)\n{\n register f32* scale asm("$15")=&D_00376224;\n asm("" : "+r"(scale));\n'
 if profile&2:text+=' f32 first=object[0x44];\n f32 second=object[0x45];\n f32 factor=*scale;\n f32 limit=object[7];\n'+(' return factor*(first+second)<=limit;\n' if profile&1 else ' return (first+second)*factor<=limit;\n')
 else:text+=(' return *scale*(object[0x44]+object[0x45])<=object[7];\n' if profile&1 else ' return (object[0x44]+object[0x45])*(*scale)<=object[7];\n')
 text+='}\n';name=f'eight_hour_002eff58_v5_expression_evaluation_{profile}.cpp';assert not(base/name).exists();(base/name).write_text(text);names.append(name)
(base/'float-predicate-v5-variants.json').write_text(json.dumps(names))
(base/'probe_float_predicate_v5.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','float-predicate-v5-variants.json'))
