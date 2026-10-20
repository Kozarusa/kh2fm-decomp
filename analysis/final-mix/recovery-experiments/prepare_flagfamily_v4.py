from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
source=(ex/'fm_primary_flagfamily_v1_00146ed8.cpp').read_text(encoding='utf-8')
for variant in range(1,4):
 body=source.replace('  if (*(char *)(param_2 + 0xeb)', '  register u32 raw asm("$15")=*(u8 *)(param_2+0xeb);\n  asm("" : "+r"(raw));\n  if ((u8)raw').replace('*(char *)(param_2 + 0xeb)','(s8)raw')
 if variant==2:
  body=body.replace('asm(""', 'asm volatile(""')
 elif variant==3:
  body=body.replace('register u32 raw asm("$15")','u32 raw')
 name=f'fm_primary_flagfamily_v4_00146ed8_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" s32 D_003a99f0;
void func_00148a68(u32 object,u32 item)
{
  register s32 *base asm("$11")=&D_003a99f0;
  asm("" : "+r"(base));
  u32 index=*(u8 *)(item+0x11f);
  s32 *cursor=base+index;
  while(*cursor!=0) { ++cursor; ++index; }
  base[index]=item;
  ++*(u32 *)(object+0x537c);
}
'''
 if variant==2:
  source=source.replace('u32 index=', 'register u32 index asm("$12")=').replace('s32 *cursor=', 'register s32 *cursor asm("$13")=').replace('  while(', '  asm("" : "+r"(cursor), "+r"(index));\n  while(')
 elif variant==3:
  source=source.replace('asm(""', 'asm volatile(""')
 name=f'fm_primary_flagfamily_v4_00148a68_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_flagfamily_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_flagfamily_v4.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
