"""Test byte-valued formal parameters without changing the confirmed float/object ABI."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for tag, original_name in [('baseline', 'eight_hour_001b1bb8_float_forward_1.cpp'), ('ordered', 'eight_hour_001b1bb8_v3_cursor_order_0.cpp')]:
    original = (base / original_name).read_text()
    source = original.replace('u32 first,u32 second,u32 third,u32 fourth', 'u8 first,u8 second,u8 third,u8 fourth')
    name = f'eight_hour_001b1bb8_v5_u8_{tag}.cpp'
    path = base / name
    assert not path.exists()
    path.write_text(source)
    names.append(name)
(base / 'byte-parameter-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_byte_parameter_profile.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'byte-parameter-variants.json'"))
print(f'Prepared {len(names)} byte-formal profiles.')
