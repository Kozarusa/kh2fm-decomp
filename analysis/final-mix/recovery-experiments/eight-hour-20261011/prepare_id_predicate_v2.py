from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for index in (0, 1):
    name = f'eight_hour_0016f770_v2_word_argument_{index}.cpp'
    text = (base / f'eight_hour_0016f770_selected_ids_{index}.cpp').read_text().replace('u64 value', 'u32 value')
    (base / name).write_text(text)
    names.append(name)
name = 'eight_hour_0016f770_v2_raw_word_shift.cpp'
text = (base / 'eight_hour_0016f770_selected_ids_1.cpp').read_text().replace('register s32 shifted asm("$2")=(s32)value>>29;\n asm("" : "+r"(shifted));', 'register s32 shifted asm("$2");\n asm("sra %0,%1,29" : "=r"(shifted) : "r"(value));')
(base / name).write_text(text)
names.append(name)
(base / 'id-predicate-v2-variants.json').write_text(json.dumps(names))
(base / 'probe_id_predicate_v2.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'id-predicate-v2-variants.json'))
