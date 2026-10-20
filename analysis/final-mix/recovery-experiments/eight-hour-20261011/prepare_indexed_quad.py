from pathlib import Path
import json
base = Path(__file__).resolve().parent
names = []
for transport in ('cpp', 'asm'):
    for pin in (0, 1):
        name = f'eight_hour_0023e788_{transport}_{pin}.cpp'
        source = '''typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
struct __attribute__((aligned(16))) Quad { u32 words[4]; };
extern "C" Quad* func_0023e788(Quad* out, u8* record, u32 index) {
  register const u8* lookup asm("$6") = record + index;
  asm("" : "+r"(lookup));
  register s32 stride asm("$14") = 320;
  asm("" : "+r"(stride));
  register s32 product asm("$15") = (s32)lookup[2916] * stride;
'''
        if pin:
            source += '  asm("" : "+r"(product));\n'
        source += '''  register const Quad* input asm("$5") = (const Quad*)(record + product + 1632);
  asm("" : "+r"(input));
'''
        source += '  *out = *input;\n' if transport == 'cpp' else '  asm volatile("lq $8,%1; sq $8,%0" : "=m"(*out) : "m"(*input) : "$8");\n'
        source += '  return out;\n}\n'
        (base / name).write_text(source)
        names.append(name)
(base / 'indexed-quad-variants.json').write_text(json.dumps(names, indent=2) + '\n')
runner = (base / 'probe_quad_copy.py').read_text().replace('quad-copy-variants.json', 'indexed-quad-variants.json')
(base / 'probe_indexed_quad.py').write_text(runner)
record_path = base.parents[0] / '..' / 'worker-coordination' / 'eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
if not any(row['phase'] == 'queuexi' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase': 'queuexi', 'functions': 2, 'instruction_bytes': 84, 'exact_total': 5849, 'checkpoint': 'primary-queuexi-checkpoint-2026-10-08.json'})
record['phase'] = 'indexed-quad-transport-recovery'
record_path.write_text(json.dumps(record, indent=2) + '\n')
