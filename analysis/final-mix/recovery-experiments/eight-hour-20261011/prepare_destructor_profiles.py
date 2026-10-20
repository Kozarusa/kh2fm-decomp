"""Express object inputs observed in both original helper exports."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
ex = base.parent
names = []
for address, helper in [('0028b7f8', '0028b8a0'), ('00315678', '003167f8'), ('00315700', '003167f8'), ('00316890', '003167f8')]:
    original = (ex / f'fm_primary_destructors_v1_{address}_1.cpp').read_text()
    for argument in ['u32', 'void*']:
        for volatile in [False, True]:
            source = original.replace(f'void func_{helper}(void)', f'void func_{helper}({argument})')
            actual = 'param_1' if argument == 'u32' else '(void*)param_1'
            source = source.replace(f'  func_{helper}();', f'  func_{helper}({actual});')
            if not volatile:
                source = source.replace('*(volatile u32 *)param_1', '*(u32 *)param_1')
            assert source != original
            name = f'eight_hour_{address}_object_{argument.replace("*", "pointer")}_{int(volatile)}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'destructor-profile-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_destructor_profiles.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'destructor-profile-variants.json'"))
print(f'Prepared {len(names)} observed-object-input profiles.')
