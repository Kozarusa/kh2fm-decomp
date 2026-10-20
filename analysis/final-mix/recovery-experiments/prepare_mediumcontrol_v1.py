from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,5):
 source=(ex/'fm_primary_mediumfresh_v1_00127d40.cpp').read_text(encoding='utf-8')
 source=source.replace('u64 func_00127d40(u64 param_1)','u32 func_00127d40(u32 param_1)').replace('u64 uVar1','u32 uVar1')
 if variant==2:
  source=source.replace('func_00127d40(u32 param_1)','func_00127d40(s32 param_1)')
 if variant==3:
  source=source.replace('u32 func_00127d40(u32 param_1)','u64 func_00127d40(u32 param_1)').replace('u32 uVar1','u64 uVar1')
 if variant==4:
  source=source.replace('u32 func_00127d40(u32 param_1)','u64 func_00127d40(s32 param_1)').replace('u32 uVar1','u64 uVar1')
 name=f'fm_primary_mediumcontrol_v1_00127d40_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for address in ['00124c48','00132018','0011eea8']:
 source=(ex/f'fm_primary_mediumfresh_v1_{address}.cpp').read_text(encoding='utf-8')
 for variant in range(1,4):
  body=source
  if address=='00124c48':
   body=body.replace('int *piVar1;','register int *piVar1 asm("$2");').replace('  if (piVar1 !=', '  asm volatile("" : "+r"(piVar1));\n  if (piVar1 !=')
   if variant==2:
    body=body.replace('if (iVar2 == -1)','if (__builtin_expect(iVar2 == -1,0))')
   if variant==3:
    body=body.replace('int iVar2;','register s32 iVar2 asm("$12");').replace('    if (iVar2 == -1)', '    asm volatile("" : "+r"(iVar2));\n    if (iVar2 == -1)')
  elif address=='00132018':
   body=body.replace('if (*param_1 != -1)',f'if (__builtin_expect(*param_1 != -1,{0 if variant==1 else 1}))')
   if variant==3:
    body=body.replace('if (param_1 == (short *)0x0)', 'if (__builtin_expect(param_1 == (short *)0x0,0))')
  else:
   body=body.replace('int iVar3;','register s32 iVar3 asm("$15");').replace('  if (iVar3 == param_2)', '  asm volatile("" : "+r"(iVar3));\n  if (__builtin_expect(iVar3 == param_2,0))')
   if variant==2:
    body=body.replace('int iVar1;','register s32 iVar1 asm("$14");')
   if variant==3:
    body=body.replace('asm volatile(', 'asm(')
  name=f'fm_primary_mediumcontrol_v1_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
runner=(ex/'probe_mediumfresh_v4.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_mediumcontrol_v1.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
