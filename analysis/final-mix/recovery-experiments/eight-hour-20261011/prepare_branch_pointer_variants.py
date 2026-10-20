"""Test pointer lifetime and condition-mode representations without flag changes."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for width in ['s64', 'u64', 's32', 'u32']:
    for pinned in [False, True]:
        for shape in ['forward', 'reverse', 'ternary', 'labels']:
            source = '#include "../common/types.h"\nextern "C" u8 D_00373a98[],D_00373aa0[];\n'
            source += f'void func_002713a0({width} a,u8**b,u32*c)\n{{\n'
            source += ' register u8* p asm("$15");\n' if pinned else ' u8* p;\n'
            if shape == 'forward':
                source += ' if(a==0)p=D_00373a98;else p=D_00373aa0;\n'
            elif shape == 'reverse':
                source += ' if(a!=0)p=D_00373aa0;else p=D_00373a98;\n'
            elif shape == 'ternary':
                source += ' p=a?D_00373aa0:D_00373a98;\n'
            else:
                source += ' if(a!=0)goto second;\n p=D_00373a98;goto publish;\n second:p=D_00373aa0;\n publish:\n'
            source += ' *b=p;register u32 count asm("$14")=3;asm volatile("" : "+r"(count) : "r"(p) : "memory");*c=count;\n}\n'
            name = f'eight_hour_002713a0_{width}_{int(pinned)}_{shape}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'branch-pointer-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_branch_pointer.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'branch-pointer-variants.json'"))
print(f'Prepared {len(names)} pointer-lifetime and condition-mode variants.')
