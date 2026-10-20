"""Retain native byte-store order, float-load order, and FPU zero transport."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
variants = []
source = (base / 'eight_hour_001b1bb8_float_forward_1.cpp').read_text()
source = source.replace('register u8* cursor', 'register volatile u8* cursor')
variants.append(('001b1bb8_v2_volatile_cursor', source))
for clobber in [False, True]:
    source = (base / 'eight_hour_001b1be0_float_forward_1.cpp').read_text()
    marker = ' asm("" : "+f"(bound)' + (' : : "$f12"' if clobber else '') + ');\n'
    source = source.replace(' func_001ad990(0.0f,*limit,scalar,object+8);', ' register f32 bound asm("$f13")=*limit;\n' + marker + ' func_001ad990(0.0f,bound,scalar,object+8);')
    variants.append((f'001b1be0_v2_bound_{int(clobber)}', source))
for volatile in [False, True]:
    qualifier = 'volatile ' if volatile else ''
    source = '#include "../common/types.h"\nextern "C" void func_001a1a20(u8*,s32,u32);\n'
    source += f'void func_001a1db8(u8* object){{register f32 zero asm("$f0")=0.0f;asm("" : "+f"(zero));*({qualifier}f32*)(object+444)=zero;*({qualifier}f32*)(object+448)=zero;func_001a1a20(object,*(s32*)(object+388),0);}}\n'
    variants.append((f'001a1db8_v2_fpu_zero_{int(volatile)}', source))
names = []
for tag, source in variants:
    name = f'eight_hour_{tag}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'float-forwarding-v2-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_float_forwarding_v2.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'float-forwarding-v2-variants.json'"))
print(f'Prepared {len(names)} narrowed float/byte transport variants.')
