from pathlib import Path
import json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py';leases=[]
names=json.loads((base/'context-field-wrapper-variants.json').read_text())+json.loads((base/'frame-pointer-control-variants.json').read_text())
for address in sorted({name.split('_')[2] for name in names}):
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1,address;leases.extend(selected)
with (base/'context-and-frame-leases.json').open('x') as stream:json.dump(leases,stream,indent=2)
(base/'harvest_context_and_frame_wrappers.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','context-and-frame-leases.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json';record=json.loads(record_path.read_text());assert not any(r['phase']=='queueiotaprime' for r in record['accepted_batches'])
record['accepted_batches'].append({'phase':'queueiotaprime','functions':7,'instruction_bytes':444,'exact_total':6003,'checkpoint':'primary-queueiotaprime-checkpoint-2026-10-08.json'})
record['phase']='context-field-and-frame-pointer-wrappers';record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} context and frame wrappers; checkpoint recorded.')
