from pathlib import Path
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
rows = json.loads((base/'global-clearing-wrapper-census.json').read_text())
helper = base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
names = []
leases = []
for row in rows:
    if row['accepted'] or row['state']!=['ready','general']:
        continue
    address = row['address']
    result = subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    claimed = json.loads(result.stdout)['leases']
    assert len(claimed)==1
    leases.extend(claimed)
    for volatile in (0,1):
        name = f'eight_hour_{address}_clearing_family_{volatile}.cpp'
        qualifier = 'volatile ' if volatile else ''
        text = f'#include "../common/types.h"\nextern "C" u8 D_{row["vtable"]};\nextern "C" u32 D_{row["cleared_global"]};\nextern "C" void func_{row["first_helper"]}(u32*);\nextern "C" void func_{row["final_helper"]}(u32*);\nvoid func_{address}(u32* object)\n{{\n *({qualifier}u32*)object=(u32)&D_{row["vtable"]};\n D_{row["cleared_global"]}=0;\n func_{row["first_helper"]}(object);\n func_{row["final_helper"]}(object);\n}}\n'
        (base/name).write_text(text)
        names.append(name)
address='002ceaa8'
result = subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True)
assert result.returncode==0,result.stdout+result.stderr
claimed=json.loads(result.stdout)['leases']
assert len(claimed)==1
leases.extend(claimed)
for mask in range(4):
    name=f'eight_hour_002ceaa8_clear_object_{mask}.cpp'
    global_qualifier='volatile ' if mask&1 else ''
    byte_qualifier='volatile ' if mask&2 else ''
    text=f'#include "../common/types.h"\nextern "C" u8 D_00361f70;\nextern "C" {global_qualifier}u32 D_00361f60;\nextern "C" void func_002cf3f8(u32*);\nextern "C" void func_00105110(u32*);\nvoid func_002ceaa8(u32* object)\n{{\n *object=(u32)&D_00361f70;\n func_002cf3f8(object);\n D_00361f60=0;\n *({byte_qualifier}u8*)((u8*)object+88)=0;\n func_00105110(object);\n}}\n'
    (base/name).write_text(text)
    names.append(name)
with (base/'clearing-family-leases.json').open('x') as stream:
    json.dump(leases,stream,indent=2)
(base/'clearing-family-variants.json').write_text(json.dumps(names))
(base/'probe_clearing_family.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','clearing-family-variants.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json'
record=json.loads(record_path.read_text())
if not any(row['phase']=='queuealphaprime' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase':'queuealphaprime','functions':57,'instruction_bytes':2964,'exact_total':5943,'checkpoint':'primary-queuealphaprime-checkpoint-2026-10-08.json'})
record['phase']='global-clearing-wrapper-recovery'
record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} functions; prepared {len(names)} isolated variants.')
