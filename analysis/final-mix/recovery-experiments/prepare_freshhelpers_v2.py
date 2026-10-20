from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
source=(ex/'fm_primary_freshhelpers_v1_0013b4b0.cpp').read_text(encoding='utf-8').replace('*(char *)','*(u8 *)')
name='fm_primary_freshhelpers_v2_0013b4b0_1.cpp'
(ex/name).write_text(source,encoding='utf-8')
names.append(name)
for address in ['001337f0','00133980']:
 source=(ex/f'fm_primary_freshhelpers_v1_{address}.cpp').read_text(encoding='utf-8')
 for variant in range(1,4):
  body=source.replace('iVar1 = *param_1;','iVar1 = *(volatile int *)param_1;')
  if variant==2:
   body=source.replace('iVar1 = *param_1;','asm volatile("" ::: "memory");\n  iVar1 = *param_1;')
  if variant==3:
   body=body.replace('int iVar1;','register s32 iVar1 asm("$2");').replace('  *param_1 = iVar1','  asm volatile("" : "+r"(iVar1));\n  *param_1 = iVar1')
  name=f'fm_primary_freshhelpers_v2_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
for variant in range(1,4):
 source=(ex/'fm_primary_freshhelpers_v1_00137458.cpp').read_text(encoding='utf-8')
 source=source.replace('    do {','    asm volatile("" : "+r"(iVar1));\n    do {').replace('      puVar2 = puVar2 + 4;','      asm volatile("" : "+r"(iVar1));\n      puVar2 = puVar2 + 4;')
 if variant==2:
  source=source.replace('int iVar1;','register s32 iVar1 asm("$14");').replace('u32 *puVar2;','register u32 *puVar2 asm("$15");')
 if variant==3:
  source=source.replace('asm volatile(', 'asm(')
 name=f'fm_primary_freshhelpers_v2_00137458_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_freshhelpers_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_freshhelpers_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
