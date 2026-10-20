from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for address in ['00123d40','00132f38']:
 source=(ex/f'fm_primary_mediumfresh_v1_{address}.cpp').read_text(encoding='utf-8')
 for variant in range(1,4):
  body=source
  if address=='00123d40':
   body=body.replace('u64 func_00124748(u64,u64)','u32 func_00124748(u32,u32)').replace('typedef u64 code(u64,u64,u64)','typedef void code(u32,u64,u64)').replace('func_00123d40(u64 param_1','func_00123d40(u32 param_1').replace('u64 uVar1','u32 uVar1')
   if variant==2:
    body=body.replace('u32 uVar1;','register u32 uVar1 asm("$2");').replace('  (**(code **)', '  asm volatile("" : "+r"(uVar1));\n  (**(code **)')
   elif variant==3:
    body=body.replace('typedef void code(u32,u64,u64)','typedef void code(u32,u32,u32)').replace('u64 param_2,u64 param_3','u32 param_2,u32 param_3')
  else:
   body=body.replace('s64 func_001325c8(u64,s32,u32)','s32 func_001325c8(u32,s32,u32)').replace('func_00132f38(u64 param_1)','func_00132f38(u32 param_1)').replace('s64 lVar2','s32 lVar2')
   if variant==2:
    body=body.replace('int iVar1;','register s32 iVar1 asm("$16");\n  register u32 object asm("$17")=param_1;\n  asm volatile("" : "+r"(object));').replace('func_001325c8(param_1,','func_001325c8(object,').replace('(int)param_1','(int)object')
   elif variant==3:
    body=body.replace('func_00132f38(u32 param_1)','func_00132f38(s32 param_1)')
  name=f'fm_primary_mediumfresh_v2_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" f32 D_0036abec;
extern "C" f32 D_0036abf0;
s32 func_001317a8(f32 value,u32 object)
{
  register u32 base asm("$15")=*(u32 *)(object+4);
  asm volatile("" : "+r"(base));
  s32 count=*(s32 *)(base+0x24);
  f32 scaled=value**(f32 *)(base+0x58);
  register f32 *denominator asm("$15")=&D_0036abec;
  asm volatile("" : "+r"(denominator));
  s32 index=(s32)(scaled / *denominator+D_0036abf0);
  if(index<0) index=0;
  if(count<=index) index=count-1;
  return index;
}
'''
 if variant==2:
  source=source.replace('scaled / *denominator+D_0036abf0','scaled / *denominator+*addition').replace('  s32 index=', '  register f32 *addition asm("$15")=&D_0036abf0;\n  asm volatile("" : "+r"(addition));\n  s32 index=')
 elif variant==3:
  source=source.replace('s32 count=','register s32 count asm("$14")=').replace('  f32 scaled=', '  asm volatile("" : "+r"(count));\n  f32 scaled=')
 name=f'fm_primary_mediumfresh_v2_001317a8_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_mediumfresh_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_mediumfresh_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
