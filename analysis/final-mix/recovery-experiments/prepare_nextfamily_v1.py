from pathlib import Path
import json,re
ex=Path(__file__).resolve().parent
pool={r['address']:r for r in json.loads((ex/'primary-fourhour-freshpool-v1.json').read_text())}
addresses=['0013c820','0013e5a8','0013e610','0013f828','00140850','00141010','00143470']
headers={
'0013c820':'extern "C" u64 func_0013b5d0(u32,u64,u64,u32,u32,u32,u32,u32,u32);\nextern "C" void func_00139570(u64);\nextern "C" u32 D_0036ad4c;\n',
'0013e5a8':'extern "C" s32 func_00139d78(u32);\nextern "C" void func_00139510(u32);\nextern "C" s32 func_0013e610(u32);\ntypedef void code(u32);\n',
'0013e610':'extern "C" void func_0013e2d8(s32,u64,u32);\nextern "C" u32 D_003486a4;\nextern "C" u32 D_003486a0;\n',
'0013f828':'extern "C" u32 func_0016c028(u32);\nextern "C" f32 D_0036adb8;\n',
'00141010':'extern "C" s64 func_00141080(void);\nextern "C" void func_001ad990(u32,u32,u32,u32);\nextern "C" u32 D_00348754;\nextern "C" u32 D_0036ae80;\nextern "C" u32 D_00348750;\n',
'00143470':'extern "C" void func_001652c8(u32,u64,u64,u64,u64,u64,u64,u64);\nextern "C" u32 D_00348804;\n'}
names=[]
for address in addresses:
 body=pool[address]['code'].replace('FUN_','func_').replace('DAT_','D_').replace('\r\n','\n')
 for old,new in [('undefined8','u64'),('undefined4','u32'),('undefined1','u8'),('uint','u32'),('long','s64')]:
  body=re.sub(r'\b'+old+r'\b',new,body)
 if address=='0013e5a8':
  body=body.replace('u64 param_1','u32 param_1').replace('s64 lVar1','s32 lVar1').replace('func_00139d78();','func_00139d78(param_1);')
 name=f'fm_primary_nextfamily_v1_{address}.cpp'
 (ex/name).write_text('#include "../common/types.h"\n// Provisional compiler proposal; complete-range proof is required.\n'+headers.get(address,'')+body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_freshhelpers_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_nextfamily_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
claims=ex.parent/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
assert not set(addresses).intersection(data['addresses'])
data['addresses']+=addresses
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
