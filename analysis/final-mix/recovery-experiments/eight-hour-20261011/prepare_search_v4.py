from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for index in range(3):
    name = f'eight_hour_001d3350_v4_register_loop_{index}.cpp'
    text = '#include "../common/types.h"\ns32* func_001d3350(s32* cursor,s32 value)\n{\n register s32 count asm("$14")=0;\n for(;count<3;++count){\n s32* result=cursor++;\n'
    if index < 2:
        text += ' asm("" : ' + ('"+r"(count)' if index else ': "r"(count)') + ');\n if(*result==value)return result;\n'
    else:
        text += ' register s32 current asm("$15")=*result;\n asm("" : "+r"(count),"+r"(current));\n if(current==value)return result;\n'
    text += ' }\n return 0;\n}\n'
    (base / name).write_text(text)
    names.append(name)
(base / 'search-v4-variants.json').write_text(json.dumps(names))
(base / 'probe_search_v4.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'search-v4-variants.json'))
