"""Make the original hidden float/object forwarding and float-zero stores explicit."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
variants = []
for cursor_marker in [False, True]:
    source = '#include "../common/types.h"\nextern "C" void func_001b1be0(f32,u8*);\n'
    source += 'void func_001b1bb8(f32 scalar,u8* object,u32 first,u32 second,u32 third,u32 fourth)\n{\n object[20]=(u8)first;\n register u8* cursor asm("$15")=object+20;\n'
    if cursor_marker:
        source += ' asm("" : "+r"(cursor));\n'
    source += ' cursor[3]=(u8)fourth;cursor[1]=(u8)second;cursor[2]=(u8)third;\n func_001b1be0(scalar,object);\n}\n'
    variants.append((f'001b1bb8_float_forward_{int(cursor_marker)}', source))
for pointer_marker in [False, True]:
    source = '#include "../common/types.h"\nextern "C" f32 D_0036d9a0;\nextern "C" void func_001ad990(f32,f32,f32,u8*);\n'
    source += 'void func_001b1be0(f32 scalar,u8* object)\n{\n'
    if pointer_marker:
        source += ' register const f32* limit asm("$15")=&D_0036d9a0;asm("" : "+r"(limit));\n func_001ad990(0.0f,*limit,scalar,object+8);\n'
    else:
        source += ' func_001ad990(0.0f,D_0036d9a0,scalar,object+8);\n'
    source += '}\n'
    variants.append((f'001b1be0_float_forward_{int(pointer_marker)}', source))
for volatile in [False, True]:
    qualifier = 'volatile ' if volatile else ''
    source = '#include "../common/types.h"\nextern "C" void func_001a1a20(u8*,s32,u32);\n'
    source += f'void func_001a1db8(u8* object){{*({qualifier}f32*)(object+444)=0.0f;*({qualifier}f32*)(object+448)=0.0f;func_001a1a20(object,*(s32*)(object+388),0);}}\n'
    variants.append((f'001a1db8_float_zero_{int(volatile)}', source))
names = []
for tag, source in variants:
    name = f'eight_hour_{tag}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'float-forwarding-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_float_forwarding.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'float-forwarding-variants.json'"))
print(f'Prepared {len(names)} confirmed float-forwarding profiles.')
