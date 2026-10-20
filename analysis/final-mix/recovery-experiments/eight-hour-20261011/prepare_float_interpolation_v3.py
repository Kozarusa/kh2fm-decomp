from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for mask in range(4):
    for marker in (0, 1, 2):
        name = f'eight_hour_001ad990_v3_{mask}_{marker}.cpp'
        first = '(*(volatile float*)(output+1))' if mask & 1 else 'output[1]'
        second = '(*(volatile float*)output)' if mask & 2 else 'output[0]'
        text = 'void func_001ad990(float start,float end,float duration,float* output)\n{\n register float zero asm("$f0")=0.0f;\n if(zero<duration){\n float difference=end-start;\n output[0]=start;\n output[1]=difference/duration;\n }else{\n'
        text += f' {first}=zero;\n'
        if marker == 1:
            text += ' asm("" : "+f"(zero));\n'
        text += f' {second}=end;\n'
        if marker == 2:
            text += ' asm("" : "+f"(zero));\n'
        text += ' }\n}\n'
        (base / name).write_text(text)
        names.append(name)
(base / 'float-interpolation-v3-variants.json').write_text(json.dumps(names))
(base / 'probe_float_interpolation_v3.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'float-interpolation-v3-variants.json'))
record_path = base.parents[1] / 'worker-coordination/eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
if not any(row['phase'] == 'queuepi' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase': 'queuepi', 'functions': 2, 'instruction_bytes': 96, 'exact_total': 5852, 'checkpoint': 'primary-queuepi-checkpoint-2026-10-08.json'})
record['phase'] = 'float-interpolation-branch-recovery'
record_path.write_text(json.dumps(record, indent=2) + '\n')
