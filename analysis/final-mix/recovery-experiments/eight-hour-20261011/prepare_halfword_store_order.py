"""Keep indexed address in incoming register five and materialize pair before stores."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base / 'eight_hour_0023e738_signed_1_1.cpp').read_text()
names = []
for indexed_first in [False, True]:
    for value_inputs in [False, True]:
        source = original.replace('register u32 indexed asm("$5")=object+index*2;', 'register u32 indexed asm("$5")=index*2+object;')
        if indexed_first:
            line = ' register u32 indexed asm("$5")=index*2+object;\n'
            source = source.replace(line, '')
            source = source.replace('{\n', '{\n' + line, 1)
        marker = 'asm("" : "+r"(pair),"+r"(indexed)'
        if value_inputs:
            marker += ' : "r"(first),"r"(second)'
        marker += ');'
        source = source.replace('asm("" : "+r"(pair));', marker)
        name = f'eight_hour_0023e738_v2_{int(indexed_first)}_{int(value_inputs)}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'halfword-store-order-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_halfword_store_order.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'halfword-store-order-variants.json'"))
print(f'Prepared {len(names)} indexed-address lifetime variants.')
