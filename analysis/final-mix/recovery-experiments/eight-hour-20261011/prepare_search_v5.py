from pathlib import Path
import json
base = Path(__file__).resolve().parent
name = 'eight_hour_001d3350_v5_increment_after_marker.cpp'
text = (base / 'eight_hour_001d3350_v4_register_loop_2.cpp').read_text().replace('s32* result=cursor++;', 's32* result=cursor;').replace('if(current==value)', '++cursor;\n if(current==value)')
(base / name).write_text(text)
(base / 'search-v5-variants.json').write_text(json.dumps([name]))
(base / 'probe_search_v5.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'search-v5-variants.json'))
