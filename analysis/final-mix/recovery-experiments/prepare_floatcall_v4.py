from pathlib import Path
ex=Path(__file__).resolve().parent
source=(ex/'fm_primary_nextfamily_v3_00141010_2.cpp').read_text(encoding='utf-8')
names=[]
for variant in range(1,4):
 body=source.replace('register State *state asm("$16")=&D_00348710;','register u32 high asm("$15");\n    asm("lui %0,0x35" : "=r"(high));\n    register State *state asm("$16")=(State *)(high-30960);')
 if variant!=2:
  body=body.replace('    if(state->object!=0)', '    register u32 object asm("$14")=state->object;\n    asm("" : "+r"(object));\n    if(object!=0)').replace('value,state->object+0x834','value,object+0x834')
 if variant==3:
  body=body.replace('register State *state asm("$16")=(State *)(high-30960);','register State *state asm("$16");\n    asm("addiu %0,%1,-30960" : "=r"(state) : "r"(high));')
 name=f'fm_primary_floatcall_v4_00141010_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_nextfamily_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatcall_v4.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
