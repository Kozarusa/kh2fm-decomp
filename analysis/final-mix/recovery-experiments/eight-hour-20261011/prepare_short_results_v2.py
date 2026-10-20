from pathlib import Path
import json
base = Path(__file__).resolve().parent
original = (base / 'eight_hour_003160e0_results_0_1.cpp').read_text()
names = []
for index, suffix in enumerate(('asm("" : : "m"(output[1]),"m"(output[3]));', 'asm("" : : : "memory");', 'asm("" : "+r"(output));', 'asm("" : "+r"(six),"+r"(eight));')):
    name = f'eight_hour_003160e0_v2_{index}.cpp'
    (base / name).write_text(original.replace('return 1;', suffix + '\n return 1;'))
    names.append(name)
for index in (0, 1):
    name = f'eight_hour_003160e0_v2_volatile_{index}.cpp'
    text = original.replace('output[1]=six;', '(*(volatile u32*)(output+1))=six;')
    if index:
        text = text.replace('output[3]=eight;', '(*(volatile u32*)(output+3))=eight;')
    (base / name).write_text(text)
    names.append(name)
(base / 'short-result-v2-variants.json').write_text(json.dumps(names))
(base / 'probe_short_results_v2.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'short-result-v2-variants.json'))
