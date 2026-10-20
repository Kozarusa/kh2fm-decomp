"""Keep a single original counter transport on the guarded loop edge."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for guard in ['nested', 'early']:
    for pointer_pinned in [False, True]:
        for instruction in ['move', 'daddu']:
            source = '#include "../common/types.h"\nextern "C" void func_001a3188(u16,s32,s32);\nvoid func_001d9630(u16* input,s32 n)\n{\n'
            source += ' if(n>0) {\n' if guard == 'nested' else ' if(n<=0)return;\n {\n'
            source += ' register s32 count asm("$16");\n'
            operation = 'move %0,%1' if instruction == 'move' else 'daddu %0,%1,$0'
            source += f' asm volatile("{operation}" : "=r"(count) : "r"(n));\n'
            source += ' register u16* p asm("$17")=input;\n' if pointer_pinned else ' u16* p=input;\n'
            source += ' do {if(*p){func_001a3188(*p,100,0);*p=0;}--count;++p;}while(count);\n }\n}\n'
            name = f'eight_hour_001d9630_v2_{guard}_{int(pointer_pinned)}_{instruction}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'loop-counter-transport-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_loop_counter_transport.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'loop-counter-transport-variants.json'"))
print(f'Prepared {len(names)} guarded counter-transport variants.')
