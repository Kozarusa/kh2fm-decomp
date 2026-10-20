from pathlib import Path
import json
ex=Path(__file__).resolve().parent
sources={}
for address,helper,table in [('001584a0','00242d58','0034a970'),('00158548','00242ce8','0034a980')]:
 sources[address]=f'''#include "../common/types.h"
extern "C" u32 func_{helper}(void);
extern "C" u8 D_{table};
bool func_{address}(u64 *flags)
{{
  u32 index=(func_{helper}()^1)&255;
  return (*flags & *(u64 *)(&D_{table}+index*8))!=0;
}}
'''
common='''#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" Quad D_0034a9c0;
extern "C" Quad D_0034a9d0;
extern "C" u32 D_0034a9e0;
extern "C" u32 D_0034a9e4;
'''
sources['00158ac8']=common+'''void func_00158ac8(u32 object)
{
  u32 source=object+0x90;
  u32 destination=(u32)&D_0034a9c0;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(D_0034a9c0) : "r"(source), "m"(*(Quad *)source) : "$8");
  source=object+0x70;
  destination=(u32)&D_0034a9d0;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(D_0034a9d0) : "r"(source), "m"(*(Quad *)source) : "$8");
  D_0034a9e0=*(u32 *)(object+0x48);
  D_0034a9e4=*(u32 *)(object+0x50);
}
'''
sources['00158b20']=common+'''void func_00158b20(u32 object)
{
  *(u32 *)(object+0x48)=D_0034a9e0;
  *(u32 *)(object+0x50)=D_0034a9e4;
  u32 source=(u32)&D_0034a9c0;
  u32 destination=object+0x90;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(D_0034a9c0) : "$8");
  source=(u32)&D_0034a9d0;
  destination=object+0x70;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(D_0034a9d0) : "$8");
}
'''
sources['00159ce0']='''#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { f32 value[4]; };
extern "C" u32 func_0016c028(u32);
extern "C" f32 D_0036b378;
void func_00159ce0(u32 object,u32 destination)
{
  u32 source=func_0016c028(*(u32 *)(object+0x44));
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(*(Quad *)source) : "$8");
  register f32 *constant asm("$15")=&D_0036b378;
  asm("" : "+r"(constant));
  *(f32 *)(destination+4)-=*constant;
}
'''
names=[]
for address,source in sources.items():
 name=f'fm_primary_maskcopy_v1_{address}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_lookupswitch_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_maskcopy_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
claims=ex.parent/'worker-coordination/primary-claim.json'
data=json.loads(claims.read_text())
assert not set(sources).intersection(data['addresses'])
data['addresses']+=list(sources)
claims.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
