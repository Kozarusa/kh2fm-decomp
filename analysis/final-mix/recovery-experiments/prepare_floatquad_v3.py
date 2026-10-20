from pathlib import Path
ex=Path(__file__).resolve().parent
source=(ex/'fm_primary_floatquad_v2_00144570_2.cpp').read_text(encoding='utf-8')
names=[]
for variant in range(1,4):
 body=source.replace('f32 radius=', 'register f32 radius asm("$f0")=').replace('f32 x=temporary.value[0],y=temporary.value[1],z=temporary.value[2];','register f32 x asm("$f1")=temporary.value[0];\n  register f32 y asm("$f2")=temporary.value[1];\n  register f32 z asm("$f3")=temporary.value[2];')
 body=body.replace('f32 px=x+radius,py=y+radius,pz=z+radius;', 'register f32 px asm("$f4")=x+radius;\n  register f32 py asm("$f5")=y+radius;\n  register f32 pz asm("$f6")=z+radius;')
 body=body.replace('f32 nx=x-radius,ny=y-radius,nz=z-radius;', 'register f32 nx asm("$f1")=x-radius;\n  register f32 ny asm("$f2")=y-radius;\n  register f32 nz asm("$f3")=z-radius;')
 if variant>=2:
  body=body.replace('  register f32 px', '  asm("" : "+f"(radius), "+f"(x), "+f"(y), "+f"(z));\n  register f32 px')
 if variant==3:
  body=body.replace('asm(""', 'asm volatile(""')
 name=f'fm_primary_floatquad_v3_00144570_{variant}.cpp'
 (ex/name).write_text(body,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_floatquad_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatquad_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
