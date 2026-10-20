"""Recover a guarded flag predicate with one observed field read."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for pin in [False, True]:
    for shift in ['cpp', 'masked_cpp', 'hardware']:
        source = '#include "../common/types.h"\nbool func_0028b1c0(const u8* object,u32 index)\n{\n'
        source += ' register u32 bits asm("$14")=*(const u32*)(object+32);\n' if pin else ' u32 bits=*(const u32*)(object+32);\n'
        source += ' if(!bits)return false;\n'
        if shift == 'hardware':
            source += ' register u32 mask asm("$15")=1;\n asm("sllv %0,%0,%1" : "+r"(mask) : "r"(index));\n'
        else:
            expression = '1u<<index' if shift == 'cpp' else '1u<<(index&31)'
            source += (' register u32 mask asm("$15")=' if pin else ' u32 mask=') + expression + ';\n'
        source += ' return (bits&mask)!=0;\n}\n'
        name = f'eight_hour_0028b1c0_{int(pin)}_{shift}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'bit-predicate-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_bit_predicate.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'bit-predicate-variants.json'"))
print(f'Prepared {len(names)} guarded bit-predicate variants.')
