from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for address in ['00305e20','0030ec28']:
 for variant in range(1,4):
  source=(ex/f'fm_primary_shortglobals_v1_{address}_2.cpp').read_text(encoding='utf-8')
  source=source.replace('asm volatile(','asm(')
  if variant==2:
   source=source.replace(': "=r"(value));',': "=r"(value) : "r"(pointer));').replace(': "=r"(mask));',': "=r"(mask) : "r"(result));')
  if variant==3:
   source=source.replace(': "=r"(value));',': "=r"(value) : "r"(pointer));').replace(': "=r"(mask));',': "=r"(mask) : "r"(result));').replace('return -1;','asm("" ::: "memory");\n  return -1;').replace('return (result&mask)!=0;','asm("" ::: "memory");\n  return (result&mask)!=0;')
  name=f'fm_primary_shortglobals_v2_{address}_{variant}.cpp'
  (ex/name).write_text(source,encoding='utf-8')
  names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" u32 D_01d49960;
void func_001c8a90(void)
{
  register u32 *base asm("$14")=&D_01d49960;
  *base=0;
  register u32 high asm("$15");
  asm volatile("lui %0,0x1d5" : "=r"(high) : : "memory");
  base[1]=0;
  *(u32 *)(high-26264)=0;
}
'''
 if variant==2:
  source=source.replace('asm volatile(', 'asm(')
 if variant==3:
  source=source.replace('  *base=0;', '  *base=0;\n  asm volatile("" : "+r"(base) : : "memory");')
 name=f'fm_primary_shortglobals_v2_001c8a90_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_shortglobals_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_shortglobals_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
