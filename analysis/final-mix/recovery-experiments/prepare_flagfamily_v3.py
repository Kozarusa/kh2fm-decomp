from pathlib import Path
ex=Path(__file__).resolve().parent
source=(ex/'fm_primary_flagfamily_v2_00148638_1.cpp').read_text(encoding='utf-8')
names=[]
for variant in range(1,5):
 body=source
 if variant<=2:
  body=body.replace('if(*(f32 *)(base+0x44)<value)',f'if(__builtin_expect(*(f32 *)(base+0x44)<value,{variant-1}))')
 else:
  body=body.replace('f32 middle=*(f32 *)(base+0x3c);','register f32 middle asm("$f1");\n  asm("lwc1 %0,0x3c(%1)" : "=f"(middle) : "r"(base) : "memory");')
  if variant==4:
   body=body.replace('asm("lwc1', 'asm volatile("lwc1')
 name=f'fm_primary_flagfamily_v3_00148638_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_flagfamily_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_flagfamily_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
