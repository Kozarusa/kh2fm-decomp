from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,3):
 source='''#include "../common/types.h"
extern "C" f32 func_00166d38(u32);
extern "C" f32 func_00166d10(u32,u32);
extern "C" void func_00154cd0(f32,u32,u32);
void func_00155658(u32 object)
{
  register f32 first asm("$f0")=func_00166d38(*(u32 *)(object+0x34));
  register u32 nested asm("$15")=*(u32 *)(object+0x34);
  asm("" : "+r"(nested));
  register f32 saved asm("$f20");
  register u32 argument asm("$4");
  asm("mov.s %0,%2; lw %1,0x24(%3)" : "=f"(saved), "=r"(argument) : "f"(first), "r"(object), "r"(nested) : "memory");
  register u32 second asm("$14")=*(u32 *)(nested+0x48c);
  asm("" : "+r"(second) : "r"(argument));
  f32 result=func_00166d10(argument,*(u32 *)(second+4));
  func_00154cd0(result,object,1);
  func_00154cd0(saved,object,2);
}
'''
 if variant==2:
  source=source.replace(' : "memory");',');')
 name=f'fm_primary_floatresult_v4_00155658_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_globalfamily_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatresult_v4.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
