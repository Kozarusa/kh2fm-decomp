from pathlib import Path
import json,re
ex=Path(__file__).resolve().parent
pool={r['address']:r for r in json.loads((ex/'primary-fourhour-freshpool-v1.json').read_text())}
addresses=['0011eea8','00123d40','00124c48','00127d40','001317a8','00132018','00132f38']
headers={
'00123d40':'extern "C" u64 func_00124748(u64,u64);\ntypedef u64 code(u64,u64,u64);\n',
'00127d40':'extern "C" void func_00127f40(s32,s32);\nextern "C" void func_001316f0(s32,s32);\n',
'001317a8':'extern "C" f32 D_0036abec;\nextern "C" f32 D_0036abf0;\n',
'00132f38':'extern "C" s32 func_00132c68(void);\nextern "C" s64 func_001325c8(u64,s32,u32);\n'}
names=[]
for address in addresses:
 body=pool[address]['code'].replace('FUN_','func_').replace('DAT_','D_')
 for old,new in [('undefined8','u64'),('undefined4','u32'),('undefined1','u8'),('uint','u32'),('long','s64')]:
  body=re.sub(r'\b'+old+r'\b',new,body)
 name=f'fm_primary_mediumfresh_v1_{address}.cpp'
 (ex/name).write_text('#include "../common/types.h"\n// Provisional decompiler recovery; no exactness is assumed.\n'+headers.get(address,'')+body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_shortglobals_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_mediumfresh_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
claims=ex.parent/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
assert not set(addresses).intersection(data['addresses'])
data['addresses']+=addresses
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
