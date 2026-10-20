from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for address, offset in (('001d97f0', 3), ('001d9820', 9)):
    for pin in (0, 1):
        name = f'eight_hour_{address}_indexed_counter_{pin}.cpp'
        source = '#include "../common/types.h"\nextern "C" u16 D_0032fafe[];\n'
        source += f'void func_{address}(u32 index)\n{{\n'
        source += ' register u16* base asm("$15")=D_0032fafe;\n'
        if pin:
            source += ' asm("" : "+r"(base));\n'
        source += ' register u16* slots asm("$4")=(u16*)(index*2+(u32)base);\n asm("" : "+r"(slots));\n'
        source += f' register u32 count asm("$14")=slots[{offset}];\n register u32 next asm("$15")=count+1;\n asm("" : "+r"(count) : "r"(next));\n if((u16)count<999)slots[{offset}]=(u16)next;\n}}\n'
        (base / name).write_text(source)
        names.append(name)
(base / 'indexed-counter-variants.json').write_text(json.dumps(names))
(base / 'probe_indexed_counters.py').write_text((base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'indexed-counter-variants.json'))
record_path = base.parents[1] / 'worker-coordination/eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
if not any(row['phase'] == 'queueomicron' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase': 'queueomicron', 'functions': 1, 'instruction_bytes': 40, 'exact_total': 5850, 'checkpoint': 'primary-queueomicron-checkpoint-2026-10-08.json'})
record['phase'] = 'indexed-halfword-counter-recovery'
record_path.write_text(json.dumps(record, indent=2) + '\n')
