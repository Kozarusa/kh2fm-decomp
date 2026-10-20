from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" f32 D_0036ad4c;
extern "C" u32 func_0013b5d0(f32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32);
extern "C" void func_00139570(u32);
void func_0013c820(u32 first,u32 second)
{
  u32 result=func_0013b5d0(D_0036ad4c,first,second,2,0,0,0,0,0,0x80e6e6e6,2);
  func_00139570(result);
}
'''
 if variant==2:
  source=source.replace('u32,u32);','u32,u64);')
 elif variant==3:
  source=source.replace('u32,u32);','u64,u32);')
 name=f'fm_primary_nextfamily_v2_0013c820_{variant}.cpp'
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
  if(func_00141080()!=0 && D_00348710.object!=0) {
    func_001ad990(0.0f,D_0036ae80,value,D_00348710.object+0x834);
    D_00348710.reset=0;
  }
}
'''
 if variant==2:
  source=source.replace('  if(func_', '  register State *state asm("$16")=&D_00348710;\n  asm volatile("" : "+r"(state));\n  if(func_').replace('D_00348710.object','state->object').replace('D_00348710.reset','state->reset')
 elif variant==3:
  source=source.replace('s32 func_00141080','s64 func_00141080')
 name=f'fm_primary_nextfamily_v2_00141010_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_nextfamily_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_nextfamily_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
