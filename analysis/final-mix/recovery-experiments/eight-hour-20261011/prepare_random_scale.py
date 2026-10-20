from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for pin in (0, 1):
    for expression in (0, 1):
        name = f'eight_hour_0023e700_random_scale_{pin}_{expression}.cpp'
        text = '#include "../common/types.h"\nextern "C" s32 func_001064a8(s32);\nextern "C" f32 D_00371560;\nf32 func_0023e700(void)\n{\n s32 random=func_001064a8(20)+10;\n'
        if pin:
            text += ' register f32* scale asm("$15")=&D_00371560;\n asm("" : "+r"(scale));\n'
        factor = '*scale' if pin else 'D_00371560'
        text += f' return (f32)random*{factor};\n}}\n' if not expression else f' register f32 converted asm("$f0")=(f32)random;\n asm("" : "+f"(converted));\n return converted*{factor};\n}}\n'
        (base / name).write_text(text)
        names.append(name)
(base / 'random-scale-variants.json').write_text(json.dumps(names))
(base / 'probe_random_scale.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'random-scale-variants.json'))
