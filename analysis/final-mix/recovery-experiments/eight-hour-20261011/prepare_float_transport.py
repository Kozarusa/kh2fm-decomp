"""Preserve the original first integer load before floating argument transport."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for pointer_marker in [False, True]:
    for integer_marker in ['none', 'output', 'dependency']:
        for float_pinned in [False, True]:
            source = '#include "../common/types.h"\nextern "C" void func_001b1bb8(f32,u32,u32,u32,u32,u32);\nvoid func_00174af8(const u32* object)\n{\n register const u32* saved asm("$15")=object;\n'
            if pointer_marker:
                source += ' asm("" : "+r"(saved));\n'
            source += ' register u32 first asm("$4")=saved[0];\n'
            if integer_marker == 'output':
                source += ' asm("" : "+r"(first));\n'
            elif integer_marker == 'dependency':
                source += ' asm("" : "+r"(first) : "r"(saved));\n'
            if float_pinned:
                source += ' register f32 scalar asm("$f12")=*(const f32*)(saved+4);\n asm("" : "+f"(scalar));\n'
            else:
                source += ' f32 scalar=*(const f32*)(saved+4);\n'
            source += ' func_001b1bb8(scalar,first,saved[1],saved[2],saved[3],0x80);\n}\n'
            name = f'eight_hour_00174af8_{int(pointer_marker)}_{integer_marker}_{int(float_pinned)}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'float-transport-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_float_transport.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'float-transport-variants.json'"))
print(f'Prepared {len(names)} first-word/float transport variants.')
