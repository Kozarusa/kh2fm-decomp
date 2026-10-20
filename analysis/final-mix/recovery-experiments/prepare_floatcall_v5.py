from pathlib import Path
ex=Path(__file__).resolve().parent
source=(ex/'fm_primary_floatcall_v4_00141010_1.cpp').read_text(encoding='utf-8')
names=[]
for variant in range(1,3):
 body=source.replace('asm("lui %0,0x35"','asm volatile("lui %0,0x35"')
 if variant==2:
  body=body.replace('    register u32 high','    asm volatile("" ::: "memory");\n    register u32 high')
 name=f'fm_primary_floatcall_v5_00141010_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_floatcall_v4.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatcall_v5.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
