from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
for variant in range(1,3):
 source=(ex/f'fm_primary_floatquad_v3_00144570_{variant}.cpp').read_text(encoding='utf-8')
 source=source.replace('register f32 nx asm("$f1")=x-radius;\n  register f32 ny asm("$f2")=y-radius;\n  register f32 nz asm("$f3")=z-radius;','x-=radius; y-=radius; z-=radius;')
 source=source.replace('(nx)','(x)').replace('(ny)','(y)').replace('(nz)','(z)').replace('=nx;','=x;').replace('=ny;','=y;').replace('=nz;','=z;')
 name=f'fm_primary_floatquad_v4_00144570_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_floatquad_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatquad_v4.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
