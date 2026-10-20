from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" f32 D_004f3580;
extern "C" f32 D_004f3584;
extern "C" f32 D_0036b200;
extern "C" f32 D_0036b204;
void func_0014ec40(s32 mode,s64 phase)
{
  if(phase==0xffff && mode==1) {
    register f32 *source asm("$15")=&D_0036b200;
    asm("" : "+r"(source));
    D_004f3580=*source;
  }
  asm("" : "+r"(mode), "+r"(phase));
  if(phase==0xffff && mode==1) {
    register f32 *source asm("$15")=&D_0036b204;
    asm("" : "+r"(source));
    D_004f3584=*source;
  }
}
'''
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 elif variant==3:
  source=source.replace('asm("" : "+r"(mode), "+r"(phase));','asm volatile("" : "+r"(mode), "+r"(phase));')
 name=f'fm_primary_pairinitializer_v2_0014ec40_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_globalfamily_v4.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_pairinitializer_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
