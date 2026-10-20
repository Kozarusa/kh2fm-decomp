from pathlib import Path
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
rows = json.loads((base / 'deleting-wrapper-census.json').read_text())
controls = [rows[0], next(row for row in rows if row['address']=='0011f5a0')]
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
names = []
leases = []
for row in controls:
    address = row['address']
    result = subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True)
    assert result.returncode == 0, result.stdout+result.stderr
    claimed = json.loads(result.stdout)['leases']
    assert len(claimed)==1
    leases.extend(claimed)
    for volatile in (0,1):
        name = f'eight_hour_{address}_deleting_control_{volatile}.cpp'
        qualifier = 'volatile ' if volatile else ''
        text = f'#include "../common/types.h"\nextern "C" u8 D_{row["vtable"]};\nextern "C" void func_{row["first_helper"]}(u32*);\nextern "C" void func_{row["final_helper"]}(u32*);\nvoid func_{address}(u32* object)\n{{\n *({qualifier}u32*)object=(u32)&D_{row["vtable"]};\n func_{row["first_helper"]}(object);\n func_{row["final_helper"]}(object);\n}}\n'
        (base/name).write_text(text)
        names.append(name)
with (base/'deleting-control-leases.json').open('x') as stream:
    json.dump(leases,stream,indent=2)
(base/'deleting-control-variants.json').write_text(json.dumps(names))
(base/'probe_deleting_controls.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','deleting-control-variants.json'))
record_path = base.parents[1] / 'worker-coordination/eight-hour-run-20261011.json'
record = json.loads(record_path.read_text())
if not any(row['phase']=='queueomega' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase':'queueomega','functions':10,'instruction_bytes':480,'exact_total':5886,'checkpoint':'primary-queueomega-checkpoint-2026-10-08.json'})
record['phase']='deleting-wrapper-family-recovery'
record_path.write_text(json.dumps(record,indent=2)+'\n')
