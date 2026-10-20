"""Prevent later loads from moving ahead of the original first word load."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for form in ['pointer_output', 'paired_output', 'volatile_locals']:
    for stage in [False, True]:
        source = '#include "../common/types.h"\nextern "C" void func_001b1bb8(f32,u32,u32,u32,u32,u32);\nvoid func_00174af8(const u32* object)\n{\n register const u32* saved asm("$15")=object;\n'
        if form == 'volatile_locals':
            source += ' register u32 first asm("$4")=*(const volatile u32*)saved;\n'
            source += ' f32 scalar=*(const volatile f32*)(saved+4);\n u32 second=*(const volatile u32*)(saved+1);\n u32 third=*(const volatile u32*)(saved+2);\n u32 fourth=*(const volatile u32*)(saved+3);\n'
        else:
            source += ' register u32 first asm("$4")=saved[0];\n'
            if form == 'pointer_output':
                source += ' asm("" : "+r"(saved) : "r"(first));\n'
            else:
                source += ' asm("" : "+r"(saved),"+r"(first));\n'
            source += ' f32 scalar=*(const f32*)(saved+4);\n'
            if stage:
                source += ' asm("" : "+r"(saved) : "f"(scalar));\n'
            source += ' u32 second=saved[1];\n u32 third=saved[2];\n u32 fourth=saved[3];\n'
        if stage:
            source += ' asm("" : "+r"(first),"+r"(second),"+r"(third),"+r"(fourth),"+f"(scalar));\n'
        source += ' func_001b1bb8(scalar,first,second,third,fourth,0x80);\n}\n'
        name = f'eight_hour_00174af8_v2_{form}_{int(stage)}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'float-transport-v2-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_float_transport_v2.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'float-transport-v2-variants.json'"))
print(f'Prepared {len(names)} ordered-load variants.')
