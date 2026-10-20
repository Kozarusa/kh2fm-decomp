from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
source=(ex/'fm_primary_maskcopy_v1_00159ce0.cpp').read_text(encoding='utf-8').replace('if(source!=destination)', 'if(destination!=source)')
name='fm_primary_maskcopy_v2_00159ce0_1.cpp'
(ex/name).write_text(source,encoding='utf-8')
names.append(name)
for variant in range(1,4):
 source='''#include "../common/types.h"
struct Masks { u64 reserved[2]; u64 values[256]; };
extern "C" Masks D_0034a970;
extern "C" u32 func_00242ce8(void);
bool func_00158548(u64 *flags)
{
  u32 index=(func_00242ce8()^1)&255;
  return (*flags&D_0034a970.values[index])!=0;
}
'''
 if variant==2:
  source=source.replace('return (*flags&D_0034a970.values[index])!=0;', 'u8 *slot=(u8 *)&D_0034a970+index*8;\n  return (*flags&*(u64 *)(slot+16))!=0;')
 if variant==3:
  source=source.replace('return (*flags&D_0034a970.values[index])!=0;', 'register u8 *base asm("$15")=(u8 *)&D_0034a970;\n  asm("" : "+r"(base) : "r"(index));\n  return (*flags&*(u64 *)(base+index*8+16))!=0;')
 name=f'fm_primary_maskcopy_v2_00158548_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
for address in ['00158ac8','00158b20']:
 source=(ex/f'fm_primary_maskcopy_v1_{address}.cpp').read_text(encoding='utf-8')
 source=source.replace('u32 D_0034a9e0','f32 D_0034a9e0').replace('u32 D_0034a9e4','f32 D_0034a9e4').replace('*(u32 *)(object+0x48)','*(f32 *)(object+0x48)').replace('*(u32 *)(object+0x50)','*(f32 *)(object+0x50)')
 for variant in range(1,3):
  body=source
  if address=='00158ac8':
   body=body.replace('u32 source=', 'register u32 source asm("$14")=').replace('u32 destination=', 'register u32 destination asm("$15")=')
   body=body.replace('sq $8,%0" : "=m"(D_0034a9c0) : "r"(source), "m"(*(Quad *)source)', 'sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(*(Quad *)source)')
   body=body.replace('sq $8,%0" : "=m"(D_0034a9d0) : "r"(source), "m"(*(Quad *)source)', 'sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(*(Quad *)source)')
   body=body.replace('if(source!=destination)', 'if(destination!=source)')
  else:
   body=body.replace('u32 source=', 'register u32 source asm("$15")=').replace('u32 destination=', 'register u32 destination asm("$13")=')
  if variant==2:
   body=body.replace('  if(', '  asm("" : "+r"(source), "+r"(destination));\n  if(')
  name=f'fm_primary_maskcopy_v2_{address}_{variant}.cpp'
  (ex/name).write_text(body,encoding='utf-8')
  names.append(name)
runner=(ex/'probe_maskcopy_v1.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_maskcopy_v2.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
