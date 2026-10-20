"""Preserve incoming low-word transport and the original nested branch shape."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for pinned_base in [False, True]:
    for volatile_result in [False, True]:
        for shape in ['nested', 'early', 'selected']:
            source = '#include "../common/types.h"\nextern "C" u32 D_0033cafc,D_0033caf4;\n'
            source += 'extern "C" ' + ('volatile ' if volatile_result else '') + 'u32 D_0033caf0;\nextern "C" u32 D_0033cb00;\n'
            source += 'void func_00105af8(s64 mode)\n{\n u32 low;asm("" : "=r"(low) : "0"(mode));\n'
            if pinned_base:
                source += ' register u32 upperBase asm("$11")=0x00340000;asm("" : "+r"(upperBase));\n register u32* table asm("$12")=(u32*)(upperBase-13568);asm("" : "+r"(table));\n'
                read_zero = '*(volatile u32*)(upperBase-13568)'
            else:
                source += ' u32* table=&D_0033cb00;\n'
                read_zero = '*(volatile u32*)&D_0033cb00'
            source += ' D_0033cafc=low;\n D_0033caf0=table[(s32)low-1];\n'
            if shape == 'nested':
                source += f' if(mode!=3) {{\n u32 selected={read_zero};\n if(mode!=8) D_0033caf4=D_0033caf0;\n else D_0033caf4=selected;\n }} else D_0033caf4=table[1];\n'
            elif shape == 'early':
                source += f' if(mode!=3) {{\n u32 selected={read_zero};\n if(mode!=8) {{D_0033caf4=D_0033caf0;return;}}\n D_0033caf4=selected;return;\n }}\n D_0033caf4=table[1];\n'
            else:
                source += f' u32 selected;\n if(mode==3) selected=table[1];\n else {{selected={read_zero};if(mode!=8) selected=D_0033caf0;}}\n D_0033caf4=selected;\n'
            source += '}\n'
            name = f'eight_hour_00105af8_v2_{int(pinned_base)}_{int(volatile_result)}_{shape}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'table-selection-v2-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_table_selection_v2.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'table-selection-v2-variants.json'"))
print(f'Prepared {len(names)} raw-transport variants.')
