from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source=(ex/'fm_primary_globalfamily_v2_00155658_1.cpp').read_text(encoding='utf-8')
 before='  uVar3 = func_00166d10(*(u32 *)(iVar1 + 0x24),\n                       *(u32 *)(*(int *)(*(int *)(iVar1 + 0x34) + 0x48c) + 4));'
 after='  register u32 nested asm("$15")=*(u32 *)(iVar1+0x34);\n  asm("" : "+r"(nested));\n  register u32 second asm("$14")=*(u32 *)(nested+0x48c);\n  asm("" : "+r"(second));\n  uVar3 = func_00166d10(*(u32 *)(iVar1+0x24),*(u32 *)(second+4));'
 assert before in source
 source=source.replace(before,after)
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 elif variant==3:
  source=source.replace('  asm("" : "+r"(second));\n','')
 name=f'fm_primary_globalfamily_v3_00155658_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,3):
 source=(ex/'fm_primary_globalfamily_v2_00157160_1.cpp').read_text(encoding='utf-8')
 before='  if ((lVar1 != 0) && ((*(u32 *)((int)lVar1 + 0x588) & 0x400000) != 0)) {'
 after='  if(lVar1 != 0) {\n    register u32 flags asm("$15")=*(u32 *)(lVar1+0x588);\n    asm("" : "+r"(flags));\n    if((flags&0x400000)!=0) {'
 assert before in source
 source=source.replace(before,after).replace('  return;\n}', '  }\n  return;\n}')
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 name=f'fm_primary_globalfamily_v3_00157160_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_globalfamily_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalfamily_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
