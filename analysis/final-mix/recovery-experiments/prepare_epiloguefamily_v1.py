from pathlib import Path
import json

ex=Path(__file__).resolve().parent
names=[]
for address in ['0014dc48','0014dca8','002e5f70']:
    prefix='fourwordfresh' if address.startswith('0014') else 'fiveword'
    source=(ex/f'fm_primary_{prefix}_v2_{address}.cpp').read_text(encoding='utf-8')
    for variant,barrier in enumerate([
        'asm volatile("" : : : "$16");',
        'asm volatile("" : : : "$17");',
        'asm volatile("" : : : "$31");',
        'asm volatile("" : : "r"(param_1));',
        'asm volatile("" : "+r"(param_1));',
    ],1):
        pos=source.rfind('  return;')
        assert pos>=0
        name=f'fm_primary_epiloguefamily_v1_{address}_{variant}.cpp'
        (ex/name).write_text(source[:pos]+'  '+barrier+'\n'+source[pos:],encoding='utf-8')
        names.append(name)

# Re-express provisional assembler globals as ordinary linker-resolved objects.
for address,global_address in [('001dc488','01d6bb00'),('001de948','01dae340'),('001e0128','01dae340'),('001e0188','01dae340')]:
    source_name=next(ex.glob(f'fm_worker_b_round*_{address}_v02.cpp'),None)
    if source_name is None:
        continue
    source=source_name.read_text(encoding='utf-8')
    start=source.index('void func_')
    body=source[start:].replace('DAT_'+global_address,'D_'+global_address)
    for variant in range(1,4):
        text='#include "../common/types.h"\nextern "C" u32 D_'+global_address+';\ntypedef void (*code)(u32,u32,u32);\n'+body
        if variant==2:
            text=text.replace('asm volatile ("");','asm volatile ("" ::: "memory");')
        elif variant==3:
            text=text.replace('asm volatile ("");','asm volatile ("" ::: "$31");')
        name=f'fm_primary_epiloguefamily_v1_{address}_{variant}.cpp'
        (ex/name).write_text(text,encoding='utf-8')
        names.append(name)

runner='''from pathlib import Path
import json,subprocess
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
audit=ex.parents[3]/'Public/tools/kh2-audit'
names=NAMES
for name in names:
 source=ex/name
 with source.with_suffix('.probe.log').open('w') as log:
  result=subprocess.run(['python3',str(audit/'probe_fm_source.py'),str(source),'--summary'],stdout=log,stderr=subprocess.STDOUT)
 if result.returncode:
  print(name,'probe failed',flush=True)
  continue
 proof=json.loads(source.with_suffix('.verification.json').read_text())
 print(name,[(r['exact_match'],r['compiled_size'],r['target_size']) for r in proof['rows']],flush=True)
'''.replace('NAMES',repr(names))
(ex/'probe_epiloguefamily_v1.py').write_text(runner,encoding='utf-8')
print(json.dumps(names))
