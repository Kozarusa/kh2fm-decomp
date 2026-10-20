from pathlib import Path
import json,re
ex=Path(__file__).resolve().parent
pool={r['address']:r for r in json.loads((ex/'primary-fourhour-freshpool-v1.json').read_text())}
addresses=['001367e0','00136968','00137458','0013b4b0','0013c7d0','001337f0','00133980']
headers={
'001367e0':'extern "C" void func_00168388(u64,u64,u32,u32);\nextern "C" s64 func_00170cd0(void);\nextern "C" void func_00102448(u64,u32);\n',
'00136968':'extern "C" void func_001369d0(void);\nextern "C" void func_001369f0(void);\nextern "C" void func_00136a50(void);\nextern "C" u32 D_00347d20;\nextern "C" u16 D_003b8b22;\nextern "C" u32 D_003b8b38;\nextern "C" u16 D_003b8b20;\nextern "C" u32 D_00347d24;\n',
'00137458':'extern "C" u32 D_00347d30;\n',
'0013b4b0':'extern "C" void func_00139858(s32);\nextern "C" void func_00139ab0(s32);\nextern "C" u32 D_003484a0;\n',
'0013c7d0':'extern "C" s64 func_0013c738(u32);\nextern "C" u32 D_003484a0;\nextern "C" u8 D_003484a4;\n'}
names=[]
for address in addresses:
 body=pool[address]['code'].replace('_DAT_','D_').replace('FUN_','func_').replace('DAT_','D_')
 for old,new in [('undefined8','u64'),('undefined4','u32'),('undefined1','u8'),('uint','u32'),('long','s64')]:
  body=re.sub(r'\b'+old+r'\b',new,body)
 name=f'fm_primary_freshhelpers_v1_{address}.cpp'
 (ex/name).write_text('#include "../common/types.h"\n// Provisional decompiler recovery; exactness requires independent proof.\n'+headers.get(address,'')+body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_mediumcontrol_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_freshhelpers_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
claims=ex.parent/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
assert not set(addresses).intersection(data['addresses'])
data['addresses']+=addresses
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
