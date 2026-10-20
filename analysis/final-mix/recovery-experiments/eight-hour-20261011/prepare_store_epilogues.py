"""Test narrowly described stores and return-address read dependencies."""
from pathlib import Path
import json

base = Path(__file__).resolve().parent
names = []
for address in ['00305ce0', '00308cd0']:
    for form in ['cpp', 'precise_asm', 'register_asm', 'return_dependency']:
        for vol in [False, True]:
            source = '#include "../common/types.h"\n'
            if address == '00305ce0':
                source += 'extern "C" s32* func_00316d08(void);\ns32 func_00305ce0(void)\n{\n s32* pointer=func_00316d08();\n register s32 value asm("$3");asm("addiu %0,$0,5" : "=r"(value));\n'
                ending = ' return -1;\n}\n'
                offset = '0'
                stored = 'value'
            else:
                source += 'extern "C" void func_00308650(void);\nvoid func_00308cd0(void)\n{\n func_00308650();\n register u32 high asm("$2");asm("lui %0,0x36" : "=r"(high));\n u32* pointer=(u32*)(high+0x60dc);\n'
                ending = '}\n'
                offset = '0'
                stored = 'zero'
                source += ' u32 zero=0;\n'
            qualifier = 'volatile ' if vol else ''
            if form == 'cpp':
                source += f' *({qualifier}u32*)pointer={stored};\n'
            elif form == 'precise_asm':
                source += f' asm ' + ('volatile' if vol else '') + f'("sw %1,%0" : "=m"(*pointer) : "r"({stored}));\n'
            elif form == 'register_asm':
                source += f' asm ' + ('volatile' if vol else '') + f'("sw %1,0(%2)" : "=m"(*pointer) : "r"({stored}),"r"(pointer));\n'
            else:
                source += ' register u32 returnAddress asm("$31");asm("" : "=r"(returnAddress));\n'
                source += f' asm ' + ('volatile' if vol else '') + f'("sw %1,0(%2)" : "=m"(*pointer) : "r"({stored}),"r"(pointer),"r"(returnAddress));\n'
            source += ending
            name = f'eight_hour_{address}_{form}_{int(vol)}.cpp'
            path = base / name
            assert not path.exists()
            path.write_text(source)
            names.append(name)
(base / 'store-epilogue-variants.json').write_text(json.dumps(names, indent=2) + '\n')
(base / 'probe_store_epilogues.py').write_text((base / 'probe_angle_variants.py').read_text().replace("'angle-variants.json'", "'store-epilogue-variants.json'"))
print(f'Prepared {len(names)} precise-store variants.')
