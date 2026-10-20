from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { f32 value[4]; };
void func_00144570(f32 *destination,f32 *source)
{
  Quad temporary;
  asm("" : "+r"(source));
  if((void *)&temporary!=(void *)source)
    asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(temporary) : "r"(source), "m"(*(Quad *)source) : "$8");
  f32 radius=source[4];
  f32 x=temporary.value[0],y=temporary.value[1],z=temporary.value[2];
  f32 px=x+radius,py=y+radius,pz=z+radius;
  f32 nx=x-radius,ny=y-radius,nz=z-radius;
  destination[3]=px; destination[4]=py; destination[5]=pz;
  destination[0]=nx; destination[1]=ny; destination[2]=nz;
}
'''
 if variant>=2:
  source=source.replace('  destination[3]=', '  asm("" : "+f"(px), "+f"(py), "+f"(pz), "+f"(nx), "+f"(ny), "+f"(nz));\n  destination[3]=')
 if variant==3:
  source=source.replace('asm(""', 'asm volatile(""')
 name=f'fm_primary_floatquad_v2_00144570_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_flagfamily_v4.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatquad_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
