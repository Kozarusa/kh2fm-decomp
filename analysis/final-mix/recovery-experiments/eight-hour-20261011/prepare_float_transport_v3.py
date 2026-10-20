"""Keep three remaining integer loads in their original ascending order."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base / 'eight_hour_00174af8_v2_pointer_output_0.cpp').read_text()
names = []
for ordered in ['volatile', 'pointer_dependencies', 'paired_dependencies']:
    for float_stage in [False, True]:
        source = original
        if float_stage:
            source = source.replace(' f32 scalar=*(const f32*)(saved+4);\n', ' f32 scalar=*(const f32*)(saved+4);\n asm("" : "+r"(saved) : "f"(scalar));\n')
        if ordered == 'volatile':
            for variable, index in [('second', 1), ('third', 2), ('fourth', 3)]:
                source = source.replace(f'u32 {variable}=saved[{index}];', f'u32 {variable}=*((const volatile u32*)saved+{index});')
        else:
            for variable, index in [('second', 1), ('third', 2)]:
                marker = f' asm("" : "+r"(saved) : "r"({variable}));\n'
                if ordered == 'paired_dependencies':
                    marker = f' asm("" : "+r"(saved),"+r"({variable}));\n'
                source = source.replace(f' u32 {variable}=saved[{index}];\n', f' u32 {variable}=saved[{index}];\n' + marker)
        name = f'eight_hour_00174af8_v3_{ordered}_{int(float_stage)}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'float-transport-v3-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_float_transport_v3.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'float-transport-v3-variants.json'"))
print(f'Prepared {len(names)} ascending integer-load variants.')
