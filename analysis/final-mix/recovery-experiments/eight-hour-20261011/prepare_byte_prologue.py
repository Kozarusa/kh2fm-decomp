"""Describe only the first native byte store while preserving solved cursor order."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base / 'eight_hour_001b1bb8_v3_cursor_order_0.cpp').read_text()
names = []
for mode in ['volatile_first', 'precise_first']:
    first = '*(volatile u8*)(object+20)=(u8)first;' if mode == 'volatile_first' else 'asm("sb %1,%0" : "=m"(object[20]) : "r"(first));'
    source = original.replace('object[20]=(u8)first;', first)
    name = f'eight_hour_001b1bb8_v4_{mode}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'byte-prologue-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_byte_prologue.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'byte-prologue-variants.json'"))
print(f'Prepared {len(names)} first-store descriptions.')
