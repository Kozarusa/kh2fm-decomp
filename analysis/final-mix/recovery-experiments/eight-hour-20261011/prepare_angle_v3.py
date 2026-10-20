"""Combine fixed threshold registers with scoped direct return values."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
text = (base / 'eight_hour_0017d160_early_pinned_barrier.cpp').read_text()
names = []
for first_constraint in [False, True]:
    for second_constraint in [False, True]:
        for branch_style in ['early', 'nested']:
            zero = 'register f32 answer asm("$f0")=0.0f;'
            limit = 'register f32 answer asm("$f0")=*limit;'
            if first_constraint:
                zero += 'asm("" : "+f"(answer));'
            if second_constraint:
                limit += 'asm("" : "+f"(answer));'
            source = text.replace('if(threshold<=dot) return 0.0f;', 'if(threshold<=dot) {' + zero + 'return answer;}')
            source = source.replace('return *limit;', limit + 'return answer;')
            if branch_style == 'nested':
                source = source.replace('asm volatile("" : : : "$15","memory");', 'else {\n asm volatile("" : : : "$15","memory");')
                source = source.replace('return func_002f8aa0(dot);\n}', 'return func_002f8aa0(dot);\n }\n}')
            name = f'eight_hour_0017d160_v3_{branch_style}_{int(first_constraint)}_{int(second_constraint)}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'angle-v3-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_angle_v3.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'angle-v3-variants.json'"))
print(f'Prepared {len(names)} scoped-return variants.')
