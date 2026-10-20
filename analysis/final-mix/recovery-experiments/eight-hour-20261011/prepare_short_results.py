from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for result in ('u32', 'u64'):
    name = f'eight_hour_001bbcc0_result_{result}.cpp'
    old = (base.parent / 'fm_worker_b_round13_001bbcc0_v02.cpp').read_text()
    text = old.replace('u8 func_001bbcc0', result + ' func_001bbcc0').replace('return (u8)uVar1;', 'return uVar1;')
    (base / name).write_text(text)
    names.append(name)
for pin in (0, 1):
    for constants in (0, 1):
        name = f'eight_hour_003160e0_results_{pin}_{constants}.cpp'
        text = '#include "../common/types.h"\nu32 func_003160e0(s32* first,s32* second,u32 payload,u32* output)\n{\n'
        if pin:
            text += ' register s32 a asm("$14")=first[1];\n register s32 b asm("$15")=second[1];\n asm("" : "+r"(a),"+r"(b));\n if(a==b){\n'
        else:
            text += ' if(first[1]==second[1]){\n'
        if constants:
            text += ' register u32 six asm("$15")=6;\n asm("" : "+r"(six));\n output[0]=payload;\n register u32 eight asm("$14")=8;\n asm("" : "+r"(eight));\n output[1]=six;\n output[3]=eight;\n'
        else:
            text += ' output[0]=payload;\n output[1]=6;\n output[3]=8;\n'
        text += ' return 1;\n }\n return 0;\n}\n'
        (base / name).write_text(text)
        names.append(name)
(base / 'short-result-variants.json').write_text(json.dumps(names))
(base / 'probe_short_results.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'short-result-variants.json'))
record_path = base.parents[1] / 'worker-coordination/eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
for phase, count, size, total in (('queuerho', 1, 52, 5853), ('queuesigma', 1, 56, 5854)):
    if not any(row['phase'] == phase for row in record['accepted_batches']):
        record['accepted_batches'].append({'phase': phase, 'functions': count, 'instruction_bytes': size, 'exact_total': total, 'checkpoint': f'primary-{phase}-checkpoint-2026-10-08.json'})
record['phase'] = 'short-result-width-recovery'
record_path.write_text(json.dumps(record, indent=2) + '\n')
