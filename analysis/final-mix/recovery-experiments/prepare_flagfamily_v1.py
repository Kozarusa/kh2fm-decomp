from pathlib import Path
import json,re
ex=Path(__file__).resolve().parent
pool={r['address']:r for r in json.loads((ex/'primary-fourhour-freshpool-v1.json').read_text())}
addresses=['00144570','00146ed8','00148638','00148a68','0014e140']
headers={
'00148a68':'extern "C" s32 D_003a99f0;\n',
'0014e140':'extern "C" u32 func_0014e648(u32);\nextern "C" void func_0014dd60(u32,u8,u8,u8);\n'}
names=[]
for address in addresses:
 body=pool[address]['code'].replace('FUN_','func_').replace('DAT_','D_').replace('\r\n','\n')
 for old,new in [('undefined8','u64'),('undefined4','u32'),('undefined1','u8'),('uint','u32'),('byte','u8'),('long','s64')]:
  body=re.sub(r'\b'+old+r'\b',new,body)
 if address=='0014e140':
  body=body.replace('u64 uVar1','u32 uVar1')
 name=f'fm_primary_flagfamily_v1_{address}.cpp'
 (ex/name).write_text('#include "../common/types.h"\n// Provisional recovery; complete-range proof is required.\n'+headers.get(address,'')+body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_nexttransport_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_flagfamily_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
claims=ex.parent/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
assert not set(addresses).intersection(data['addresses'])
data['addresses']+=addresses
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
