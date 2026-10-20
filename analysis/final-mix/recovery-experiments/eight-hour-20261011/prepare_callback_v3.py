"""Explore narrow memory/address dependencies around the two remaining swaps."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base / 'eight_hour_00102bd8_v2_0_0_both.cpp').read_text()
variants = []
for first_marker in ['', ' asm volatile("" : : "m"(table[9]));\n', ' asm volatile("" : "+r"(high) : "m"(table[9]));\n', ' asm volatile("" : "+r"(high) : "m"(table[9]) : "memory");\n']:
    for final_marker in ['', ' asm("" : "+r"(finalAddress));\n', ' asm("" : "+r"(finalAddress) : "r"(high));\n']:
        source = original.replace(' table[9]=first;\n', ' table[9]=first;\n' + first_marker)
        source = source.replace(' table[8]=high+0x2a70;\n D_0032b994=0;', ' register u32* finalAddress asm("$15")=&D_0032b994;\n' + final_marker + ' table[8]=high+0x2a70;\n *finalAddress=0;')
        variants.append(source)
for qualifier in ['', 'volatile ']:
    for inline_barrier in ['', 'asm volatile("" ::: "memory");']:
        source = '#include "../common/types.h"\ntypedef void (*Callback)(void);\nstruct CallbackTable{u8 padding[32];Callback first;Callback second;};\n'
        source += f'extern "C" {qualifier}CallbackTable D_0032b968;\nextern "C" u32 D_0032b994;\nextern "C" void func_00102a70(void),func_00102b90(void),func_00102b58(void);\n'
        source += f'void func_00102bd8(void){{D_0032b968.second=func_00102b90;{inline_barrier}D_0032b968.first=func_00102a70;D_0032b994=0;func_00102b58();}}\n'
        variants.append(source)
names = []
for index, source in enumerate(variants):
    name = f'eight_hour_00102bd8_v3_{index:02d}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'callback-v3-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_callback_v3.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'callback-v3-variants.json'"))
print(f'Prepared {len(names)} memory/address/type variants.')
