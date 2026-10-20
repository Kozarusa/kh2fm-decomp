"""Order the three native byte stores through the existing cursor lifetime."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base / 'eight_hour_001b1bb8_float_forward_1.cpp').read_text()
names = []
for memory_input in [False, True]:
    source = original
    first_marker = 'asm("" : "+r"(cursor)' + (' : "m"(cursor[3])' if memory_input else '') + ');'
    second_marker = 'asm("" : "+r"(cursor)' + (' : "m"(cursor[1])' if memory_input else '') + ');'
    source = source.replace('cursor[3]=(u8)fourth;cursor[1]=(u8)second;cursor[2]=(u8)third;',
                            f'cursor[3]=(u8)fourth;{first_marker}cursor[1]=(u8)second;{second_marker}cursor[2]=(u8)third;')
    name = f'eight_hour_001b1bb8_v3_cursor_order_{int(memory_input)}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'byte-cursor-order-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_byte_cursor_order.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'byte-cursor-order-variants.json'"))
print(f'Prepared {len(names)} cursor-lifetime store-order variants.')
