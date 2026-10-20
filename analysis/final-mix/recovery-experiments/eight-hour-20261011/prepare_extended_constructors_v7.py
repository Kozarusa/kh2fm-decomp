from pathlib import Path
import json,sqlite3,subprocess,sys
base=Path(__file__).resolve().parent
helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
subprocess.run([sys.executable,str(helper),'status'],check=True,stdout=subprocess.DEVNULL)
db=sqlite3.connect((base.parents[1]/'worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
leases=[]
for old in json.loads((base/'extended-constructor-leases.json').read_text()):
 address=old['address'];state,queue=db.execute('select state,queue from targets where address=?',(address,)).fetchone()
 assert state=='ready',(address,state)
 result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--queue',queue,'--count','1','--address',address],capture_output=True,text=True,check=True)
 selected=json.loads(result.stdout)['leases'];assert len(selected)==1
 leases.extend(selected)
(base/'extended-constructor-renewed-leases.json').write_text(json.dumps(leases,indent=2))
(base/'harvest_extended_renewed.py').write_text((base/'harvest_extended_constructors.py').read_text().replace('extended-constructor-leases.json','extended-constructor-renewed-leases.json'))
names=[]
for address in ('001ae9a0','001aea00'):
 for profile in range(4):
  text=(base/f'eight_hour_{address}_v6_flag_transport_{profile%2}.cpp').read_text()
  global_name='D_0036d858' if address=='001ae9a0' else 'D_0036d85c'
  old=f' register f32* scale asm("$15")=&{global_name};\n asm("" : "+r"(scale) : "m"(*(f32*)(nested+264)));'
  assert old in text
  low=-10152 if address=='001ae9a0' else -10148
  qualifier='volatile ' if profile//2 else ''
  new=f' register u32 high asm("$15");\n asm {qualifier}("lui %0,0x37" : "=r"(high) : "r"(nested),"m"(object[0x162]));\n register f32* scale asm("$15")=(f32*)(high+({low}));\n asm("" : "+r"(scale) : "m"(*(f32*)(nested+264)));'
  text=text.replace(old,new)
  name=f'eight_hour_{address}_v7_global_dependency_{profile}.cpp'
  assert not (base/name).exists();(base/name).write_text(text);names.append(name)
(base/'extended-constructor-v7-variants.json').write_text(json.dumps(names))
(base/'probe_extended_constructors_v7.py').write_text((base/'probe_extended_constructors_v6.py').read_text().replace('extended-constructor-v6-variants.json','extended-constructor-v7-variants.json'))
print('Reclaimed eight expired leases; prepared eight dependency probes.')
