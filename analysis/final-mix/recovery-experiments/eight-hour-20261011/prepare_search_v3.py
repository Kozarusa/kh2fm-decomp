from pathlib import Path
import json
base = Path(__file__).resolve().parent
bodies = [
    's32 count=0;for(;count<3;++count){s32* result=cursor++;if(*result==value)return result;}return 0;',
    's32 count=0;s32 current=*cursor;do{s32* result=cursor++;if(current==value)return result;}while(++count<3 && (current=*cursor,1));return 0;',
    's32 count=0;do{s32* result=cursor++;if(*result==value)return result;}while(++count<3);return 0;',
    's32 count=0;s32* result;do{result=cursor++;if(*result==value)break;}while(++count<3);if(count==3)return 0;return result;',
]
names = []
for index, body in enumerate(bodies):
    name = f'eight_hour_001d3350_v3_loop_shape_{index}.cpp'
    (base / name).write_text('#include "../common/types.h"\ns32* func_001d3350(s32* cursor,s32 value){\n' + body + '\n}\n')
    names.append(name)
(base / 'search-v3-variants.json').write_text(json.dumps(names))
(base / 'probe_search_v3.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'search-v3-variants.json'))
