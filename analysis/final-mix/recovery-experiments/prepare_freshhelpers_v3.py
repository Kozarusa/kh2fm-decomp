from pathlib import Path
import re
ex=Path(__file__).resolve().parent
names=[]
for address in ['001337f0','00133980']:
 source=(ex/f'fm_primary_freshhelpers_v1_{address}.cpp').read_text(encoding='utf-8')
 source=re.sub(r'\n\s*\n','\n',source)
 for variant in range(1,4):
  body=source.replace('*(short *)*param_1','*(volatile short *)*param_1').replace('iVar1 = *param_1;','iVar1 = *(volatile int *)param_1;')
  if variant>=2:
   arg='param_2' if address=='001337f0' else 'param_3'
   before=f'  *param_1 = iVar1 + {arg} * 0x10 + 0x10;\n  return iVar1 + 0x10;'
   after=f'  u32 next=iVar1 + {arg} * 0x10 + 0x10;\n  iVar1+=0x10;\n  asm volatile("" : "+r"(iVar1) : "r"(next));\n  *param_1=next;\n  return iVar1;'
   assert before in body
   body=body.replace(before,after)
  if variant==3:
   body=body.replace('asm volatile(', 'asm(')
  name=f'fm_primary_freshhelpers_v3_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
extern "C" void func_001369d0(void);
extern "C" void func_001369f0(void);
extern "C" void func_00136a50(void);
extern "C" u32 D_00347d20;
extern "C" u16 D_003b8b20;
extern "C" u32 D_003b8b38;
extern "C" u32 D_00347d24;
void func_00136968(void)
{
  func_001369d0(); func_001369f0();
  D_00347d20=0xffffffff;
  u16 *pair=&D_003b8b20;
  pair[1]=0xffff;
  D_003b8b38=0xffffffff;
  pair[0]=0xffff;
  D_00347d24=0xffffffff;
  func_00136a50();
}
'''
 if variant==2:
  source=source.replace('u16 *pair=', 'register u16 *pair asm("$12")=').replace('  pair[1]=', '  asm("" : "+r"(pair));\n  pair[1]=')
 if variant==3:
  source=source.replace('u16 *pair=', 'register volatile u16 *pair asm("$12")=').replace('  pair[1]=', '  asm volatile("" : "+r"(pair));\n  pair[1]=')
 name=f'fm_primary_freshhelpers_v3_00136968_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_freshhelpers_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_freshhelpers_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
