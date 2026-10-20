"""Constrain saved-register lifetime before the original positive-count guard."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
original = (base.parent / 'queue-run-20261009/recovery-b/recovery_b_001d9630_b40129bc_scoped.cpp').read_text()
names = []
for clobber in ['"$16"', '"$17"', '"$16","$17"']:
    for memory in [False, True]:
        addition = clobber + (',"memory"' if memory else '')
        source = original.replace('{ if(n<=0)', '{ asm volatile("" : : : ' + addition + '); if(n<=0)')
        assert source != original
        name = f'eight_hour_001d9630_clobber_{clobber.count("$")}_{clobber.replace(chr(34), "").replace("$", "").replace(",", "_")}_{int(memory)}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'loop-save-order-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_loop_save_order.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'loop-save-order-variants.json'"))
print(f'Prepared {len(names)} saved-register lifetime variants.')
