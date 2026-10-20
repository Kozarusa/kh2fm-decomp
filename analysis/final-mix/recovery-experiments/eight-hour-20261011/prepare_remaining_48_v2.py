from pathlib import Path
import json
base = Path(__file__).resolve().parent
sources = {}
for marker in (0, 1):
    text = '#include "../common/types.h"\nextern "C" u32 D_0033cae8[];\nbool func_002f1ae0(u32 index)\n{\n register u32 bits asm("$2")=D_0033cae8[index>>5];\n index&=31;\n'
    if marker:
        text += ' asm("" : "+r"(bits));\n'
    text += ' register u32 mask asm("$15")=1;\n asm("" : "+r"(mask) : "r"(bits));\n return (bits&(mask<<index))!=0;\n}\n'
    sources[f'eight_hour_002f1ae0_v2_mask_transport_{marker}.cpp'] = text
    text = (base / 'eight_hour_00311050_stack_payload_0.cpp').read_text().replace('func_00305a50(3,payload);', 'register s32 operation asm("$4")=3;\n asm("" : "+r"(operation)' + (' : "m"(payload[0]),"m"(payload[1])' if marker else '') + ');\n func_00305a50(operation,payload);')
    sources[f'eight_hour_00311050_v2_operation_register_{marker}.cpp'] = text
    text = (base / 'eight_hour_0031e068_three_vtables_1.cpp').read_text().replace('object[0]=first;', 'object[0]=first;\n asm("" : "+m"(object[0]),"+m"(object[36]),"+m"(object[104]));')
    if marker:
        text = text.replace('object[36]=second;', 'object[36]=second;\n asm("" : "+m"(object[36]),"+m"(object[104]));')
    sources[f'eight_hour_0031e068_v2_store_dependencies_{marker}.cpp'] = text
    text = (base / 'eight_hour_00308dc0_ring_index_1.cpp').read_text().replace('s32 index=numerator%denominator;', 'register s32 index asm("$2")=numerator%denominator;\n register s32 first asm("$5")=object[5];\n asm("" : "+r"(first)' + (',"+r"(index)' if marker else '') + ');').replace('return object[5]+index*64;', 'return first+index*64;')
    sources[f'eight_hour_00308dc0_v2_remainder_transport_{marker}.cpp'] = text
for marker in range(4):
    text = '#include "../common/types.h"\nextern "C" s32 func_00311450(s32);\ns32 func_00311460(s32 value)\n{\n register u32 offset asm("$2")=value-13;\n'
    if marker & 1:
        text += ' asm("" : "+r"(offset));\n'
    condition = '__builtin_expect(offset<35,0)' if marker & 2 else 'offset<35'
    text += f' s32 result;\n if({condition}){{\n result=func_00311450(value);\n asm volatile("");\n }}else{{\n result=-1;\n }}\n return result;\n}}\n'
    sources[f'eight_hour_00311460_v2_shared_epilogue_{marker}.cpp'] = text
for marker in (0, 1):
    text = '#include "../common/types.h"\ns32* func_001d3350(s32* cursor,s32 value)\n{\n register s32 count asm("$14")=0;\n'
    if marker:
        text += ' asm("" : "+r"(count));\n'
    text += ' s32 current=*cursor;\n do{\n s32* result=cursor++;\n if(current==value)return result;\n ++count;\n if(count<3)current=*cursor;\n }while(count<3);\n return 0;\n}\n'
    sources[f'eight_hour_001d3350_v2_advance_before_guard_{marker}.cpp'] = text
for name, text in sources.items():
    (base / name).write_text(text)
(base / 'remaining-48-v2-variants.json').write_text(json.dumps(list(sources)))
(base / 'probe_remaining_48_v2.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'remaining-48-v2-variants.json'))
