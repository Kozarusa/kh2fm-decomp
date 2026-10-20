from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_001d3350_v6_counter_lifetime_0.cpp').read_text()
names = []
for index in (0, 1):
    name = f'eight_hour_001d3350_v7_scoped_word_{index}.cpp'
    expression = 'register s32 current asm("$15")=*result;asm("" : "+r"(current));if(current==value)return result;'
    if index:
        expression = '{' + expression + '}'
    text = original.replace('if(*result==value)return result;', expression)
    (base / name).write_text(text)
    names.append(name)
(base / 'search-v7-variants.json').write_text(json.dumps(names))
(base / 'probe_search_v7.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'search-v7-variants.json'))
