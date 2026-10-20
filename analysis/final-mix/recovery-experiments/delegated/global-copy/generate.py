from pathlib import Path
ex=Path('Codex/analysis/final-mix/recovery-experiments'); out=ex/'delegated/global-copy'
a=(ex/'fm_primary_globalcopy_v3_00158ac8_1.cpp').read_text()
a=a.replace('register u32 destination asm("$15")=(u32)&D_0034a9c0;', 'register u32 destination asm("$15");\n  asm("lui %0,%%hi(D_0034a9c0)" : "=r"(destination));\n  asm("addiu %0,%0,%%lo(D_0034a9c0)" : "+r"(destination));')
a=a.replace('destination=(u32)&D_0034a9d0;', 'asm("lui %0,%%hi(D_0034a9d0)" : "=r"(destination));\n  asm("addiu %0,%0,%%lo(D_0034a9d0)" : "+r"(destination));')
(out/'sa_copy_ac8_symbolic.cpp').write_text(a)
b=(ex/'fm_primary_globalcopy_v3_00158b20_1.cpp').read_text()
b=b.replace('register u32 source asm("$15")=(u32)&D_0034a9c0;', 'register u32 source asm("$15");\n  asm("lui %0,%%hi(D_0034a9c0)" : "=r"(source));\n  asm("addiu %0,%0,%%lo(D_0034a9c0)" : "+r"(source));')
b=b.replace('source=(u32)&D_0034a9d0;', 'asm("lui %0,%%hi(D_0034a9d0)" : "=r"(source));\n  asm("addiu %0,%0,%%lo(D_0034a9d0)" : "+r"(source));')
b=b.replace('register u32 final_destination asm("$4")=object+0x70;', 'object+=0x70;').replace('final_destination','object')
(out/'sa_copy_b20_symbolic.cpp').write_text(b)
