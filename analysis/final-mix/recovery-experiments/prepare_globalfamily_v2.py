from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for address in ['00157160','00155658','0014f578']:
 source=(ex/f'fm_primary_globalfamily_v1_{address}.cpp').read_text(encoding='utf-8')
 for variant in range(1,3):
  body=source
  if address=='00157160':
   body=body.replace('u64 param_1','u32 param_1').replace('func_001024a8(u64)','func_001024a8(u32)')
   if variant==2:
    body=body.replace('u32 lVar1','s32 lVar1').replace('u32 func_0017df58','s32 func_0017df58')
  elif address=='00155658':
   body=body.replace('u64 param_1','u32 param_1').replace('u32 func_00166d38','f32 func_00166d38').replace('u32 func_00166d10','f32 func_00166d10').replace('func_00154cd0(u32,u64,u32)','func_00154cd0(f32,u32,u32)').replace('u32 uVar2','f32 uVar2').replace('u32 uVar3','f32 uVar3')
   if variant==2:
    body=body.replace('  iVar1 = (int)param_1;', '  register u32 call_object asm("$4")=param_1;\n  asm("" : "+r"(call_object));\n  iVar1 = (int)call_object;')
  else:
   body=body.replace('s64 lVar1','s32 lVar1')
   if variant==2:
    body=body.replace('  lVar1 =', '  register u64 saved asm("$17")=param_1;\n  asm("" : "+r"(saved));\n  lVar1 =').replace('D_0034a42c,param_1','D_0034a42c,saved')
  name=f'fm_primary_globalfamily_v2_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
runner=(ex/'probe_globalfamily_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalfamily_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
