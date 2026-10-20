from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for address in ['001050d8','0016c7a0','0016fac8','00288be8','0028cc08']:
 source=(ex/f'fm_primary_callbackreturn_v1_{address}_3.cpp').read_text(encoding='utf-8')
 for variant in range(1,4):
  body=source.replace('  register u32 object asm("$4");','  register u32 caller asm("$6")=(u32)__builtin_return_address(0);\n  asm volatile("" : "+r"(caller) : "r"(high));\n  register u32 object asm("$4");')
  body=body.replace('(u32)__builtin_return_address(0));','caller);')
  if variant==2:
   body=body.replace('register u32 caller asm("$6")=(u32)__builtin_return_address(0);\n  asm volatile("" : "+r"(caller) : "r"(high));','register u32 caller asm("$6");\n  asm volatile("move %0,$31" : "=r"(caller) : "r"(high));')
  elif variant==3:
   body=body.replace('"r"(high) : "memory"','"r"(high), "r"(caller) : "memory"')
  name=f'fm_primary_callbackreturn_v2_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
runner=(ex/'probe_callbackreturn_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_callbackreturn_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
