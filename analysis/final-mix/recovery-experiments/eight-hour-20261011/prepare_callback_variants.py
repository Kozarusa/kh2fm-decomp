"""Schedule the second callback address high word before the first store."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for base_pinned in [False, True]:
    for first_pinned in [False, True]:
        for dependency in ['first', 'base', 'both']:
            source = '#include "../common/types.h"\nextern "C" char D_0032b968;\nextern "C" u32 D_0032b994;\nextern "C" void func_00102b90(void),func_00102b58(void);\n'
            source += '// Original callback 00102a70 has high word 00100000 and positive low offset 2a70.\nvoid func_00102bd8(void)\n{\n'
            if base_pinned:
                source += ' register volatile u32* table asm("$13")=(volatile u32*)&D_0032b968;\n'
            else:
                source += ' volatile u32* table=(volatile u32*)&D_0032b968;\n'
            if first_pinned:
                source += ' register u32 first asm("$15")=(u32)&func_00102b90;\n'
            else:
                source += ' u32 first=(u32)&func_00102b90;\n'
            source += ' register u32 high asm("$14")=0x00100000;\n'
            if dependency == 'first':
                source += ' asm("" : "+r"(first) : "r"(high));\n'
            elif dependency == 'base':
                source += ' asm("" : "+r"(table) : "r"(high));\n'
            else:
                source += ' asm("" : "+r"(first),"+r"(table) : "r"(high));\n'
            source += ' table[9]=first;\n table[8]=high+0x2a70;\n D_0032b994=0;\n func_00102b58();\n}\n'
            name = f'eight_hour_00102bd8_{int(base_pinned)}_{int(first_pinned)}_{dependency}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'callback-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_callback.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'callback-variants.json'"))
print(f'Prepared {len(names)} high-word scheduling variants.')
