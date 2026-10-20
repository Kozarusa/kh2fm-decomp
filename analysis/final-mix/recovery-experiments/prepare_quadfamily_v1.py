from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
void func_00140850(u32 object)
{
  register u32 destination asm("$14")=object+0x90;
  register u32 source asm("$15")=object+0x80;
  asm("" : "+r"(destination), "+r"(source));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source),"r"(destination),"m"(*(Quad *)source) : "$8");
  destination=object+0x70;
  source=object+0x60;
  asm("" : "+r"(destination), "+r"(source));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source),"r"(destination),"m"(*(Quad *)source) : "$8");
  source=object+0xa0;
  register u32 final_destination asm("$4")=object+0xb0;
  asm("" : "+r"(final_destination), "+r"(source));
  if(final_destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)final_destination) : "r"(source),"r"(final_destination),"m"(*(Quad *)source) : "$8");
}
'''
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 if variant==3:
  source=source.replace('"m"(*(Quad *)source) : "$8"','"m"(*(Quad *)source) : "$8", "memory"')
 name=f'fm_primary_quadfamily_v1_00140850_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" u32 func_0016c028(u32);
extern "C" f32 D_0036adb8;
void func_0013f828(u32 object)
{
  register u32 saved asm("$17")=object;
  asm("" : "+r"(saved));
  register u32 destination asm("$16")=saved+0x80;
  u32 source=func_0016c028(*(u32 *)(saved+0x44));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source),"r"(destination),"m"(*(Quad *)source) : "$8");
  register f32 *constant asm("$15")=&D_0036adb8;
  asm("" : "+r"(constant));
  *(f32 *)(saved+0x84)-=*constant;
}
'''
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 if variant==3:
  source=source.replace('  register f32 *constant', '  asm volatile("" ::: "memory");\n  register f32 *constant')
 name=f'fm_primary_quadfamily_v1_0013f828_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_floatcall_v5.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_quadfamily_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
