from pathlib import Path
import json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py';leases=[]
for address in sorted({name.split('_')[2] for name in json.loads((base/'fresh60-64-variants.json').read_text())}):
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1,address;leases.extend(selected)
with (base/'fresh60-64-leases.json').open('x') as stream:json.dump(leases,stream,indent=2)
(base/'harvest_fresh60_64.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','fresh60-64-leases.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json';record=json.loads(record_path.read_text());assert not any(r['phase']=='queueetaprime' for r in record['accepted_batches'])
record['accepted_batches'].append({'phase':'queueetaprime','functions':3,'instruction_bytes':168,'exact_total':5986,'checkpoint':'primary-queueetaprime-checkpoint-2026-10-08.json'})
record['phase']='fresh-60-64-byte-full-ABI-wrappers';record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} fresh wrappers; recorded accepted checkpoint.')
