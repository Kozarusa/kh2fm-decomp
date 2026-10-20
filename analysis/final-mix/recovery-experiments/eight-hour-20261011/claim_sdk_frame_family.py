from pathlib import Path
import json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py';leases=[]
names=json.loads((base/'sdk-frame-family-variants.json').read_text())
for address in sorted({name.split('_')[2] for name in names}):
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1,address;leases.extend(selected)
with (base/'sdk-frame-family-leases.json').open('x') as stream:json.dump(leases,stream,indent=2)
(base/'harvest_sdk_frame_family.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','sdk-frame-family-leases.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json';record=json.loads(record_path.read_text());assert not any(r['phase']=='queuekappaprime' for r in record['accepted_batches'])
record['accepted_batches'].append({'phase':'queuekappaprime','functions':11,'instruction_bytes':676,'exact_total':6014,'checkpoint':'primary-queuekappaprime-checkpoint-2026-10-08.json','link_repair':'recovery-experiments/eight-hour-20261011/queuekappaprime-native-alignment-repair.json'})
record['phase']='sdk-frame-pointer-wrapper-family';record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} SDK frame wrappers; checkpoint recorded.')
