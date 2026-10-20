from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
struct __attribute__((aligned(8))) Color { u32 value; };
extern "C" f32 D_0036ad4c;
extern "C" u32 func_0013b5d0(f32,u32,u32,u32,u32,u32,u32,u32,u32,Color,u32);
extern "C" void func_00139570(u32);
void func_0013c820(u32 first,u32 second)
{
  Color color={0x80e6e6e6};
  register f32 *value asm("$14")=&D_0036ad4c;
  asm volatile("" : "+r"(value));
  u32 result=func_0013b5d0(*value,first,second,2,0,0,0,0,0,color,2);
  func_00139570(result);
}
'''
 if variant==2:
  source=source.replace('asm volatile(', 'asm(')
 elif variant==3:
  source=source.replace('  Color color={0x80e6e6e6};','  Color color;\n  color.value=0x80e6e6e6;')
 name=f'fm_primary_nextfamily_v3_0013c820_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
struct State { u8 reserved[0x40]; u32 reset; u32 object; };
extern "C" State D_00348710;
extern "C" f32 D_0036ae80;
extern "C" s32 func_00141080(void);
extern "C" void func_001ad990(f32,f32,f32,u32);
void func_00141010(f32 value)
{
  if(func_00141080()!=0) {
    register State *state asm("$16")=&D_00348710;
    asm volatile("" : "+r"(state));
    if(state->object!=0) {
      register f32 *argument asm("$15")=&D_0036ae80;
      asm volatile("" : "+r"(argument));
      func_001ad990(0.0f,*argument,value,state->object+0x834);
      state->reset=0;
    }
  }
}
'''
 if variant==2:
  source=source.replace('asm volatile(', 'asm(')
 elif variant==3:
  source=source.replace('s32 func_00141080','s64 func_00141080')
 name=f'fm_primary_nextfamily_v3_00141010_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_nextfamily_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_nextfamily_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
