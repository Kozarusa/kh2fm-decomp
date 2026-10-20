from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source=(ex/'fm_primary_nextfamily_v1_00143470.cpp').read_text(encoding='utf-8')
 source=source.replace('  return;', '  asm volatile("");\n  return;')
 if variant==2:
  source=source.replace('u64','u32')
 elif variant==3:
  source=source.replace('asm volatile("");','asm volatile("" ::: "memory");')
 name=f'fm_primary_nexttransport_v1_00143470_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" u32 D_003486a4;
extern "C" u32 D_003486a0;
extern "C" void func_0013e2d8(u32,u32,u32);
s32 func_0013e610(u32 param)
{
  u32 base=D_003486a4;
  register s32 index asm("$14")=*(s32 *)(base+0x1fa4)-1;
  register u32 scaled asm("$15")=(u32)index*4;
  asm("" : "+r"(scaled) : "r"(index));
  *(u32 *)(base+0x1fa4)=index;
  register u32 entry asm("$13")=*(u32 *)(base+scaled+0x1f80);
  asm("" : "+r"(entry));
  u32 result=base+entry*0x380;
  func_0013e2d8(result,param,D_003486a0+0x20);
  return result;
}
'''
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 elif variant==3:
  source=source.replace('  u32 base=', '  register u32 argument asm("$5")=param;\n  asm("" : "+r"(argument));\n  u32 base=').replace('result,param,','result,argument,')
 name=f'fm_primary_nexttransport_v1_0013e610_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_quadfamily_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_nexttransport_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
