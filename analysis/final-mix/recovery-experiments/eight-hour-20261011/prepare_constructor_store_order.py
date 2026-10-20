"""Preserve the two final original object stores without altering computations."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
ex = base.parent
names = []
for address in ['001c2c98', '001c2ce8']:
    original = (ex / f'fm_worker_b_round24_{address}_v02.cpp').read_text()
    table_store = '*(u32 *)param_1 = (u32)(long)&func_00351468;'
    flag_store = '*(u32 *)((u8 *)param_1 + 2748) = uVar2;'
    assert table_store in original and flag_store in original
    for mode in ['both_volatile', 'table_volatile', 'flag_volatile', 'memory_barrier']:
        source = original
        if mode in ['both_volatile', 'table_volatile']:
            source = source.replace(table_store, table_store.replace('*(u32 *)', '*(volatile u32 *)'))
        if mode in ['both_volatile', 'flag_volatile']:
            source = source.replace(flag_store, flag_store.replace('*(u32 *)', '*(volatile u32 *)'))
        if mode == 'memory_barrier':
            source = source.replace(table_store, table_store + '\n  asm volatile("" ::: "memory");')
        name = f'eight_hour_{address}_{mode}.cpp'
        path = base / name
        assert not path.exists()
        path.write_text(source)
        names.append(name)
(base / 'constructor-store-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_constructor_stores.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'constructor-store-variants.json'"))
print(f'Prepared {len(names)} final object-store order variants.')
