from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,3):
 source=(ex/'fm_primary_pairinitializer_v2_0014ec40_1.cpp').read_text(encoding='utf-8')
 source=source.replace('  if(phase==0xffff && mode==1) {','  if(phase==0xffff) {\n  if(mode==1) {',1)
 source=source.replace('    D_004f3580=*source;\n  }\n  asm("" : "+r"(mode), "+r"(phase));','    D_004f3580=*source;\n    asm("" : "+r"(mode), "+r"(phase));\n  }')
 source=source.replace('    D_004f3584=*source;\n  }\n}', '    D_004f3584=*source;\n  }\n  }\n}')
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 name=f'fm_primary_globalresidual_v5_0014ec40_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,3):
 source=(ex/'fm_primary_globalfamily_v4_0014fba0_2.cpp').read_text(encoding='utf-8')
 source=source.replace('  iVar1 = 0;', '  iVar1 = 0;\n  asm("" : "+r"(iVar1));')
 if variant==2:
  source=source.replace('int iVar1;', 'register s32 iVar1 asm("$13");')
 name=f'fm_primary_globalresidual_v5_0014fba0_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
expressions=['D_0034a784 * value + (D_0034a788 * value * value + D_0034a780)','(D_0034a780 + D_0034a788 * value * value) + D_0034a784 * value','D_0034a784 * value + D_0034a780 + D_0034a788 * value * value']
for variant,expression in enumerate(expressions,1):
 source=f'''#include "../common/types.h"
extern "C" f32 D_0036b254;
extern "C" f32 D_0034a788;
extern "C" f32 D_0034a780;
extern "C" f32 D_0034a784;
f32 func_00153610(f32 value)
{{
  f32 denominator={expression};
  register f32 *constant asm("$15")=&D_0036b254;
  asm("" : "+r"(constant));
  f32 numerator=*constant;
  f32 result=numerator/denominator;
  if(numerator<result) result=numerator;
  if(result<0.0f) result=0.0f;
  return result;
}}
'''
 name=f'fm_primary_globalresidual_v5_00153610_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_pairinitializer_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalresidual_v5.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
