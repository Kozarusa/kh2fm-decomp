from pathlib import Path
import json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py';leases=[]
addresses=sorted({name.split('_')[2] for name in json.loads((base/'fresh-scalar-wrapper-variants.json').read_text())})
for address in addresses:
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1,address;leases.extend(selected)
with (base/'fresh-scalar-wrapper-leases.json').open('x') as stream:json.dump(leases,stream,indent=2)
(base/'harvest_fresh_scalar_wrappers.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','fresh-scalar-wrapper-leases.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json';record=json.loads(record_path.read_text());assert not any(r['phase']=='queuezetaprime' for r in record['accepted_batches'])
record['accepted_batches'].append({'phase':'queuezetaprime','functions':2,'instruction_bytes':168,'exact_total':5983,'checkpoint':'primary-queuezetaprime-checkpoint-2026-10-08.json'})
record['phase']='fresh-scalar-float-and-SDK-wrappers';record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} scalar and ABI wrappers.')
