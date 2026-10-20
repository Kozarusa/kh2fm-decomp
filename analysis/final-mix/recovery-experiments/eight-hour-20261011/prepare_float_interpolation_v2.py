from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for mask in range(4):
    for marker in (0, 1):
        name = f'eight_hour_001ad990_v2_{mask}_{marker}.cpp'
        first = '(*(volatile float*)(output+1))' if mask & 1 else 'output[1]'
        second = '(*(volatile float*)output)' if mask & 2 else 'output[0]'
        text = 'void func_001ad990(float start,float end,float duration,float* output)\n{\n register float zero asm("$f0")=0.0f;\n if(!(zero<duration)){\n'
        text += f' {first}=zero;\n {second}=end;\n'
        if marker:
            text += ' asm("" : "+f"(zero) : "r"(output));\n'
        text += ' return;\n }\n float difference=end-start;\n output[0]=start;\n output[1]=difference/duration;\n}\n'
        (base / name).write_text(text)
        names.append(name)
(base / 'float-interpolation-v2-variants.json').write_text(json.dumps(names))
(base / 'probe_float_interpolation_v2.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'float-interpolation-v2-variants.json'))
