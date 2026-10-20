"""Vary only unused callee result transport and promoted first argument type."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base.parent / 'queue-run-20261009/recovery-b/recovery_b_001d9630_b40129bc_scoped.cpp').read_text()
names = []
for result in ['void', 'u32', 's32', 'u64', 's64']:
    for first in ['u16', 'u32', 's32']:
        if result == 'void' and first == 'u16':
            continue
        source = original.replace('void func_001a3188(u16,s32,s32)', f'{result} func_001a3188({first},s32,s32)')
        name = f'eight_hour_001d9630_v3_{result}_{first}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'loop-call-profile-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_loop_call_profile.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'loop-call-profile-variants.json'"))
print(f'Prepared {len(names)} narrow callee transport profiles.')
