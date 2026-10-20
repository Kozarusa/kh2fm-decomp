from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for index in range(4):
    name = f'eight_hour_0030a690_v2_{index}.cpp'
    text = '#include "../common/types.h"\nextern "C" void func_002fde18(u8*,u32,u32);\nu32 func_0030a690(void)\n{\n register u32 address asm("$2")=0x00360000;\n register u32 callback asm("$4")=0x01e40000;\n'
    if index == 0:
        text += ' asm("" : "+r"(address),"+r"(callback));\n'
    elif index == 1:
        text += ' asm("" : "+r"(address));\n asm("" : "+r"(callback));\n'
    elif index == 2:
        text += ' asm("" : "+r"(address) : "r"(callback));\n'
    else:
        text += ' asm("" : "+r"(callback) : "r"(address));\n'
    text += ' *(u32*)(address+0x6164)=0;\n func_002fde18((u8*)(callback-30296),0,4);\n return 0;\n}\n'
    (base / name).write_text(text)
    names.append(name)
(base / 'sdk-global-v2-variants.json').write_text(json.dumps(names))
(base / 'probe_sdk_globals_v2.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'sdk-global-v2-variants.json'))
record_path = base.parents[1] / 'worker-coordination/eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
for phase, count, size, total in (('queuetau', 2, 100, 5856), ('queueupsilon', 3, 144, 5859)):
    if not any(row['phase'] == phase for row in record['accepted_batches']):
        record['accepted_batches'].append({'phase': phase, 'functions': count, 'instruction_bytes': size, 'exact_total': total, 'checkpoint': f'primary-{phase}-checkpoint-2026-10-08.json'})
record['phase'] = 'sdk-global-address-and-conditional-read-recovery'
record_path.write_text(json.dumps(record, indent=2) + '\n')
