from pathlib import Path
import json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py';leases=[]
for address in ('002d96d8','002d9730'):
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1,address;leases.extend(selected)
with (base/'byte-float-constructor-leases.json').open('x') as stream:json.dump(leases,stream,indent=2)
(base/'harvest_byte_float_constructors.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','byte-float-constructor-leases.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json';record=json.loads(record_path.read_text());assert not any(r['phase']=='queueepsilonprime' for r in record['accepted_batches'])
record['accepted_batches'].append({'phase':'queueepsilonprime','functions':8,'instruction_bytes':448,'exact_total':5981,'checkpoint':'primary-queueepsilonprime-checkpoint-2026-10-08.json','link_repair':'recovery-experiments/eight-hour-20261011/queueepsilonprime-link-repair.json'})
record['phase']='mixed-byte-float-constructor-family';record_path.write_text(json.dumps(record,indent=2)+'\n')
print('Claimed two constructors; recorded published checkpoint.')
