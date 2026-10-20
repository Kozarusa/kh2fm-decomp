from pathlib import Path
import json,re
ex=Path(__file__).resolve().parent
pool={r['address']:r for r in json.loads((ex/'primary-fourhour-freshpool-v1.json').read_text())}
addresses=['0014ec40','0014f578','0014fba0','00153610','00155658','00155ee8','00155fc0','00157160']
headers={
'0014ec40':'extern "C" f32 D_004f3580;\nextern "C" f32 D_004f3584;\nextern "C" f32 D_0036b200;\nextern "C" f32 D_0036b204;\n',
'0014f578':'extern "C" u32 D_0034a42c;\nextern "C" s32 func_00150bc0(u32);\nextern "C" void func_00150940(u32);\nextern "C" void func_001507b8(u32,u64);\n',
'0014fba0':'extern "C" u8 D_0034a458;\n',
'00153610':'extern "C" f32 D_0036b254;\nextern "C" f32 D_0034a788;\nextern "C" f32 D_0034a780;\nextern "C" f32 D_0034a784;\n',
'00155658':'extern "C" u32 func_00166d38(u32);\nextern "C" u32 func_00166d10(u32,u32);\nextern "C" void func_00154cd0(u32,u64,u32);\n',
'00157160':'extern "C" u32 func_0017df58(u32);\nextern "C" void func_001574a0(u32);\nextern "C" void func_001024a8(u64);\n'}
names=[]
for address in addresses:
 body=pool[address]['code'].replace('FUN_','func_').replace('DAT_','D_').replace('\r\n','\n')
 for old,new in [('undefined8','u64'),('undefined4','u32'),('undefined2','u16'),('undefined1','u8'),('uint','u32'),('byte','u8'),('long','s64')]:
  body=re.sub(r'\b'+old+r'\b',new,body)
 if address=='00157160':
  body=body.replace('s64 lVar1','u32 lVar1')
 name=f'fm_primary_globalfamily_v1_{address}.cpp'
 (ex/name).write_text('#include "../common/types.h"\n// Provisional compiler proposal; types remain subject to original-byte proof.\n'+headers.get(address,'')+body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_floatquad_v4.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalfamily_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
claims=ex.parent/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
assert not set(addresses).intersection(data['addresses'])
data['addresses']+=addresses
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
