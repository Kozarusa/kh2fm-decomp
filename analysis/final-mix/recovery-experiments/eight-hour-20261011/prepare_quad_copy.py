"""Expose the second address high-word instruction to delay-slot scheduling."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
ex = base.parent
original = (ex / 'delegated/global-copy/sa_copy_ac8_symbolic.cpp').read_text()
second_pair = '  asm("lui %0,%%hi(D_0034a9d0)" : "=r"(destination));\n  asm("addiu %0,%0,%%lo(D_0034a9d0)" : "+r"(destination));'
first_pair = '  asm("lui %0,%%hi(D_0034a9c0)" : "=r"(destination));\n  asm("addiu %0,%0,%%lo(D_0034a9c0)" : "+r"(destination));'
assert second_pair in original and first_pair in original
names = []
for second_form in ['symbolic', 'numeric_high', 'numeric_high_input', 'numeric_address']:
    for first_form in ['opaque', 'numeric_high', 'symbolic']:
        source = original
        if second_form == 'symbolic':
            replacement = '  destination=(u32)&D_0034a9d0;\n  asm("" : "+r"(destination));'
        elif second_form == 'numeric_high':
            replacement = '  destination=0x00350000;\n  asm("" : "+r"(destination));\n  destination-=0x5630;'
        elif second_form == 'numeric_high_input':
            replacement = '  destination=0x00350000;\n  asm("" : "+r"(destination) : "r"(source));\n  destination-=0x5630;'
        else:
            replacement = '  destination=0x0034a9d0;\n  asm("" : "+r"(destination));'
        source = source.replace(second_pair, replacement)
        if first_form == 'numeric_high':
            source = source.replace(first_pair, '  destination=0x00350000;\n  asm("" : "+r"(destination));\n  destination-=0x5640;')
        elif first_form == 'symbolic':
            source = source.replace(first_pair, '  destination=(u32)&D_0034a9c0;\n  asm("" : "+r"(destination));')
        name = f'eight_hour_00158ac8_{first_form}_{second_form}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'quad-copy-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_quad_copy.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'quad-copy-variants.json'"))
print(f'Prepared {len(names)} compiler-visible address materialization variants.')
