"""Recover 00105af8 using the complete original table and selection flow."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for width in ['s64', 's32']:
    for volatile in [False, True]:
        for pinned in [False, True]:
            qualifier = 'volatile ' if volatile else ''
            source = '#include "../common/types.h"\n'
            source += f'extern "C" {qualifier}u32 D_0033cafc,D_0033caf0,D_0033caf4;\n'
            source += f'extern "C" {qualifier}u32 D_0033cb00;\n'
            source += f'void func_00105af8({width} mode)\n{{\n'
            pointer = f'{qualifier}u32* table=&D_0033cb00;\n'
            if pinned:
                pointer = f'register {qualifier}u32* table asm("$12")=&D_0033cb00;\n asm("" : "+r"(table));\n'
            source += ' ' + pointer
            source += ' D_0033cafc=(u32)mode;\n D_0033caf0=table[(s32)mode-1];\n'
            source += ' if(mode==3) D_0033caf4=table[1];\n else if(mode==8) D_0033caf4=table[0];\n else D_0033caf4=D_0033caf0;\n}\n'
            name = f'eight_hour_00105af8_{width}_{int(volatile)}_{int(pinned)}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'table-selection-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_table_selection.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'table-selection-variants.json'"))
print(f'Prepared {len(names)} table-selection variants.')
