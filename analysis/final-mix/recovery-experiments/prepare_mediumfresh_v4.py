from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
source=(ex/'fm_primary_mediumfresh_v3_00132f38_1.cpp').read_text(encoding='utf-8')
for variant in range(1,4):
 before='register u32 address asm("$15")=base+*(u32 *)(base+0x1c)+scaled;\n    asm volatile("" : "+r"(address));'
 after='register u32 address asm("$15")=*(u32 *)(base+0x1c);\n    asm volatile("" : "+r"(address));\n    address=base+address;\n    asm volatile("" : "+r"(address));\n    address=scaled+address;\n    asm volatile("" : "+r"(address));'
 if variant==2:
  after='register u32 address asm("$15")=*(u32 *)(base+0x1c);\n    asm("addu %0,%1,%0" : "+r"(address) : "r"(base));\n    asm("addu %0,%1,%0" : "+r"(address) : "r"(scaled));'
 elif variant==3:
  after=after.replace('asm volatile(', 'asm(')
 assert before in source
 body=source.replace(before,after)
 name=f'fm_primary_mediumfresh_v4_00132f38_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_mediumfresh_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_mediumfresh_v4.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
