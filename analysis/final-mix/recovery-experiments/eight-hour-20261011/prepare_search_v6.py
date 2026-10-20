from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_001d3350_v3_loop_shape_0.cpp').read_text().replace('s32 count=0;', 'register s32 count asm("$14")=0;')
names = []
for index in range(3):
    name = f'eight_hour_001d3350_v6_counter_lifetime_{index}.cpp'
    if index == 0:
        text = original.replace('if(*result==value)return result;', 'if(*result==value)return result;asm("" : "+r"(count));')
    elif index == 1:
        text = original.replace('if(*result==value)return result;', 'if(*result==value)return result;asm("" : : "r"(count));')
    else:
        text = original.replace('for(;count<3;', 'asm("" : : "r"(count));for(;count<3;')
    (base / name).write_text(text)
    names.append(name)
(base / 'search-v6-variants.json').write_text(json.dumps(names))
(base / 'probe_search_v6.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'search-v6-variants.json'))
