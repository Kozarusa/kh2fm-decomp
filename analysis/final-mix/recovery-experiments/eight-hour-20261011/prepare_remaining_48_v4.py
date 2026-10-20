from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
text = (base / 'eight_hour_0031e068_v3_high_transport_1.cpp').read_text().replace('first-=29352;', 'asm volatile("addiu %0,%0,-29352" : "+r"(first) : "r"(second));')
sources['eight_hour_0031e068_v4_low_transport.cpp'] = text
for marker in (0, 1):
    text = '#include "../common/types.h"\ns32 func_00308dc0(s32* object)\n{\n register s32 numerator asm("$5")=object[9];\n register s32 denominator asm("$3")=object[6];\n asm("" : "+r"(numerator),"+r"(denominator));\n'
    text += ' asm volatile(".set noreorder\\n div $zero,%0,%1\\n beqzl %1,1f\\n break 7\\n1:\\n .set reorder" : : "r"(numerator),"r"(denominator) : "hi","lo","memory");\n'
    text += ' register s32 first asm("$5")=object[5];\n register s32 index asm("$2");\n asm volatile("mfhi %0" : "=r"(index) : "r"(first));\n register s32 next asm("$3")=index+1;\n'
    if marker:
        text += ' asm("" : "+r"(next));\n'
    text += ' object[9]=next;\n return first+index*64;\n}\n'
    sources[f'eight_hour_00308dc0_v4_division_primitive_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'remaining-48-v4-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_remaining_48_v4.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'remaining-48-v4-variants.json'))
