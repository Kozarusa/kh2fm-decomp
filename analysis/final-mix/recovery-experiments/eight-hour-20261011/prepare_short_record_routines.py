"""Use original register classes to recover short record forwarding routines."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
variants = [
    ('002e7b88_float4', '#include "../common/types.h"\nextern "C" void func_002eac70(f32,f32,f32,f32);\nvoid func_002e7b88(const f32* record){func_002eac70(record[0],record[1],record[2],record[3]);}\n'),
]
for condition in ['bool', 'u32']:
    source = '#include "../common/types.h"\n' + f'extern "C" void func_00188b68(u32,u32,{condition});\n'
    source += 'void func_0016e718(const u32* record){func_00188b68(record[0],record[1],record[2]!=0);}\n'
    variants.append((f'0016e718_{condition}', source))
    source = source.replace('void func_0016e718(const u32* record){', 'void func_0016e718(const u32* record){register u32 first asm("$15")=record[0];asm("" : "+r"(first));')
    source = source.replace('func_00188b68(record[0],record[1],record[2]!=0)', 'func_00188b68(first,record[1],record[2]!=0)')
    variants.append((f'0016e718_{condition}_first', source))
for flag_type in ['u8', 'u32']:
    source = '#include "../common/types.h"\n' + f'void func_00182838(u32* record,u32 first,u32 third,{flag_type} flag)\n{{\n record[0]=first;record[1]=1;record[2]=third;if((u8)flag)record[1]=3;\n}}\n'
    variants.append((f'00182838_{flag_type}', source))
names = []
for tag, source in variants:
    name = f'eight_hour_{tag}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'short-record-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_short_records.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'short-record-variants.json'"))
print(f'Prepared {len(names)} original-register-class profiles.')
