from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source=(ex/'fm_primary_quadfamily_v1_0013f828_1.cpp').read_text(encoding='utf-8')
 source=source.replace('  asm("" : "+r"(saved));','  register u32 call_object asm("$4")=object;\n  asm("" : "+r"(saved), "+r"(call_object));')
 source=source.replace('  u32 source=func_0016c028(*(u32 *)(saved+0x44));','  asm("" : "+r"(destination), "+r"(call_object));\n  u32 source=func_0016c028(*(u32 *)(call_object+0x44));')
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 elif variant==3:
  source=source.replace('  asm("" : "+r"(saved), "+r"(call_object));','  asm("" : "+r"(call_object));')
 name=f'fm_primary_quadfamily_v2_0013f828_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for variant in range(1,4):
 source=(ex/'fm_primary_quadfamily_v1_00140850_1.cpp').read_text(encoding='utf-8')
 source=source.replace('  register u32 final_destination asm("$4")=object+0xb0;\n  asm("" : "+r"(final_destination), "+r"(source));','  asm("" : "+r"(source) : "r"(object));\n  register u32 final_destination asm("$4")=object+0xb0;\n  asm("" : "+r"(final_destination) : "r"(source));')
 if variant==2:
  source=source.replace('asm(""', 'asm volatile(""')
 elif variant==3:
  source=source.replace('void func_00140850(u32 object)', 'void func_00140850(register u32 object asm("$4"))')
 name=f'fm_primary_quadfamily_v2_00140850_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_quadfamily_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_quadfamily_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
