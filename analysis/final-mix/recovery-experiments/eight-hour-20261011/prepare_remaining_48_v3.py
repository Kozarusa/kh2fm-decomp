from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
for marker in range(3):
    text = '#include "../common/types.h"\nextern "C" s32 func_00311450(s32);\ns32 func_00311460(s32 value)\n{\n register u32 offset asm("$2")=value-13;\n register s32 result asm("$2");\n if(offset>=35){\n result=-1;\n'
    text += ('asm("" : "+r"(result));', 'asm volatile("" : : "r"(result));', 'asm volatile("" : "+r"(result));')[marker] + '\n'
    text += ' }else{\n result=func_00311450(value);\n asm volatile("");\n }\n return result;\n}\n'
    sources[f'eight_hour_00311460_v3_invalid_result_{marker}.cpp'] = text
for marker in (0, 1):
    text = '#include "../common/types.h"\nextern "C" void func_00106420(u32*);\nvoid func_0031e068(u32* object)\n{\n register u32 second asm("$13")=0x00350000;\n asm("" : "+r"(second));\n register u32 first asm("$15");\n asm volatile("lui %0,0x35" : "=r"(first));\n second-=31080;\n first-=29352;\n object[0]=first;\n asm("" : : : "memory");\n object[36]=second;\n'
    if marker:
        text += ' asm("" : : : "memory");\n'
    text += ' object[104]=second;\n func_00106420(object);\n}\n'
    sources[f'eight_hour_0031e068_v3_high_transport_{marker}.cpp'] = text
for marker in (0, 1):
    text = (base / 'eight_hour_00311050_stack_payload_0.cpp').read_text()
    word = ' volatile' if marker else ''
    text = text.replace('func_00305a50(3,payload);', f'register s32 operation asm("$4");\n asm{word}("li %0,3" : "=r"(operation));\n func_00305a50(operation,payload);')
    sources[f'eight_hour_00311050_v3_operation_transport_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'remaining-48-v3-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_remaining_48_v3.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'remaining-48-v3-variants.json'))
