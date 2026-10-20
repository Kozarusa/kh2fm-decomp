from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,3):
 source=(ex/'fm_primary_globalfamily_v1_0014fba0.cpp').read_text(encoding='utf-8')
 source=source.replace('(iVar3 + iVar1) * 2','iVar1 * 6')
 if variant==2:
  source=source.replace('  iVar3 = 0;','  iVar3 = iVar1*2;').replace('    iVar3 = iVar1 * 2;','    asm("" : "+r"(iVar1));')
 name=f'fm_primary_globalfamily_v4_0014fba0_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,3):
 source=(ex/'fm_primary_globalfamily_v1_00153610.cpp').read_text(encoding='utf-8').replace('0.0','0.0f')
 if variant==2:
  source=source.replace('float fVar1;','register f32 fVar1 asm("$f0");').replace('  if (D_0036b254 < fVar1)', '  asm("" : "+f"(fVar1));\n  if (D_0036b254 < fVar1)')
 name=f'fm_primary_globalfamily_v4_00153610_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_floatresult_v4.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalfamily_v4.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
