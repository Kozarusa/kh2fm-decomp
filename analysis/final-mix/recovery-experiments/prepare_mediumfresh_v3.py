from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" s32 func_00132c68(void);
extern "C" s32 func_001325c8(u32,s32,u32);
void func_00132f38(u32 param_1)
{
  register u32 object asm("$17")=param_1;
  asm volatile("" : "+r"(object));
  register s32 base asm("$16")=func_00132c68();
  s32 index=func_001325c8(object,0,*(u32 *)(base+0x24));
  if(index>=0) {
    register u32 scaled asm("$14")=(u32)index*4;
    asm volatile("" : "+r"(scaled));
    register u32 address asm("$15")=base+*(u32 *)(base+0x1c)+scaled;
    asm volatile("" : "+r"(address));
    register u32 value asm("$14")=*(u32 *)address;
    asm volatile("" : "+r"(value));
    *(u32 *)(object+0x274)=base+value;
  }
}
'''
 if variant==2:
  source=source.replace('asm volatile("" : "+r"(scaled));','asm("" : "+r"(scaled));').replace('asm volatile("" : "+r"(address));','asm("" : "+r"(address));')
 if variant==3:
  source=source.replace('    *(u32 *)(object+0x274)=base+value;','    value=base+value;\n    asm volatile("" : "+r"(value));\n    *(u32 *)(object+0x274)=value;')
 name=f'fm_primary_mediumfresh_v3_00132f38_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,5):
 source=(ex/'fm_primary_mediumfresh_v2_001317a8_2.cpp').read_text(encoding='utf-8')
 source=source.replace('  register f32 *addition', '  register f32 divided asm("$f12")=scaled / *denominator;\n  asm volatile("" : "+f"(divided));\n  register f32 *addition')
 source=source.replace('scaled / *denominator+*addition','divided+increment')
 source=source.replace('  s32 index=', '  register f32 increment asm("$f1")=*addition;\n  asm volatile("" : "+f"(increment));\n  s32 index=')
 if variant==2:
  source=source.replace('asm volatile("" : "+f"(increment));','asm("" : "+f"(increment));')
 if variant>=3:
  source=source.replace('s32 count=*(s32 *)(base+0x24);','s32 count=*(s32 *)(base+0x24);\n  register s32 limit asm("$13")=count-1;\n  asm volatile("" : "+r"(limit));').replace('index=count-1','index=limit')
 if variant==4:
  source=source.replace('asm volatile("" : "+f"(divided));','asm("" : "+f"(divided));')
 name=f'fm_primary_mediumfresh_v3_001317a8_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_mediumfresh_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_mediumfresh_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
