from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for pin in (0, 1):
    for volatile in (0, 1):
        name = f'eight_hour_001ad990_interpolation_{pin}_{volatile}.cpp'
        qualifier = 'volatile ' if volatile else ''
        text = f'void func_001ad990(float start,float end,float duration,{qualifier}float* output)\n{{\n'
        text += ' register float zero asm("$f0")=0.0f;\n'
        if pin:
            text += ' asm("" : "+f"(zero));\n'
        text += ' if(zero<duration){\n float difference=end-start;\n output[0]=start;\n output[1]=difference/duration;\n }else{\n output[1]=zero;\n output[0]=end;\n }\n}\n'
        (base / name).write_text(text)
        names.append(name)
(base / 'float-interpolation-variants.json').write_text(json.dumps(names))
(base / 'probe_float_interpolation.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'float-interpolation-variants.json'))
