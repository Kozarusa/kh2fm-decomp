from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
source=(ex/'fm_primary_flagfamily_v1_0014e140.cpp').read_text(encoding='utf-8')
for variant in range(1,5):
 body=source.replace('extern "C" u32 func_0014e648','extern "C" char D_00349f00;\nextern "C" u32 func_0014e648').replace('func_0014e648(0x349f00)','func_0014e648((u32)&D_00349f00)')
 if variant==2:
  body=body.replace('u8 param_1','u32 param_1').replace('  uVar1 =', '  register u32 first asm("$16")=param_1&255;\n  asm("" : "+r"(first));\n  uVar1 =').replace('uVar1,param_1,','uVar1,first,')
 if variant==3:
  body=body.replace('void func_0014dd60(u32,u8,u8,u8)','void func_0014dd60(u32,u32,u32,u32)')
 if variant==4:
  body=body.replace('u8 param_1','u32 param_1').replace('  uVar1 =', '  u8 first=(u8)param_1;\n  uVar1 =').replace('uVar1,param_1,','uVar1,first,')
 name=f'fm_primary_flagfamily_v2_0014e140_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
void func_00148638(f32 value,u64 unused,u32 object)
{
  u32 base=*(u32 *)(object+0x114);
  u8 previous=*(u8 *)(object+0x10d);
  f32 last=*(f32 *)(base+0x38);
  f32 middle=*(f32 *)(base+0x3c);
  u8 result;
  if(*(f32 *)(base+0x44)<value) result=2;
  else if(*(f32 *)(base+0x40)<value) result=previous;
  else if(middle<value) result=1;
  else if(last<value) result=previous;
  else result=0;
  *(u8 *)(object+0x10d)=result;
}
'''
 if variant>=2:
  source=source.replace('f32 last=', 'register f32 last asm("$f2")=').replace('f32 middle=', 'register f32 middle asm("$f1")=').replace('  u8 result;', '  asm("" : "+f"(last), "+f"(middle));\n  u8 result;')
 if variant==3:
  source=source.replace('asm(""', 'asm volatile(""')
 name=f'fm_primary_flagfamily_v2_00148638_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_flagfamily_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_flagfamily_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
