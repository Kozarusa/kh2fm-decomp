from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
extern const void *D_0036b2c4[5];
extern const void *D_0036b2ec[5];
u32 func_00155ee8(u32 object)
{
  static const void *targets[5] asm("fm_switch_table_00155ee8")={&&fallback,&&fallback,&&case2,&&case3,&&case4};
  u32 child=*(u32 *)(object+0x34);
  if(!child) goto fallback;
  u32 index=*(u8 *)(*(u32 *)(child+0x48c)+0x1af);
  if(index>=5) goto fallback;
  goto *D_0036b2c4[index];
case4: return 0x12;
fallback: return 0x15;
case2: return 0x32;
case3: return 0x8c;
}
u32 func_00155fc0(u32 object)
{
  static const void *targets[5] asm("fm_switch_table_00155fc0")={&&fallback,&&fallback,&&case2,&&case3,&&fallback};
  u32 child=*(u32 *)(object+0x34);
  if(!child) goto fallback;
  u32 index=*(u8 *)(*(u32 *)(child+0x48c)+0x1af);
  if(index>=5) goto fallback;
  goto *D_0036b2ec[index];
case2: return 0x31;
case3: return 0x8b;
fallback: return 0x19;
}
'''
 if variant==2:
  source=source.replace('u32 child=', 'register u32 child asm("$15")=').replace('u32 index=', 'register u32 index asm("$15")=')
 elif variant==3:
  source=source.replace('u32 func_', 's32 func_')
 name=f'fm_primary_lookupswitch_v1_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_globalresidual_v5.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_lookupswitch_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
