from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,4):
 source=(ex/f'fm_primary_lookupswitch_v1_{variant}.cpp').read_text(encoding='utf-8')
 source=source.replace('  u32 child=', '  u32 index;\n  u32 child=').replace('  u32 index=','  index=')
 if variant==2:
  source=source.replace('  register u32 child asm("$15")=', '  register u32 index asm("$15");\n  register u32 child asm("$15")=').replace('  register u32 index asm("$15")=', '  index=')
 name=f'fm_primary_lookupswitch_v2_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_lookupswitch_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_lookupswitch_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
