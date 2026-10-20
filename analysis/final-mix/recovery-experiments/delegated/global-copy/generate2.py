from pathlib import Path
out=Path('Codex/analysis/final-mix/recovery-experiments/delegated/global-copy')
a=(out/'sa_copy_ac8_symbolic.cpp').read_text()
for addr in ['0034a9c0','0034a9d0']:
 a=a.replace('asm("addiu %0,%0,%%lo(D_'+addr+')" : "+r"(destination));', 'destination+=(s32)(s16)0x'+addr[-4:]+';')
(out/'sa_copy_ac8_high.cpp').write_text(a)
b=(out/'sa_copy_b20_symbolic.cpp').read_text().replace('"m"(D_0034a9c0)', '"m"(*(Quad *)source)').replace('"m"(D_0034a9d0)', '"m"(*(Quad *)source)')
(out/'sa_copy_b20_memory.cpp').write_text(b)
for addr in ['0034a9c0','0034a9d0']:
 b=b.replace('asm("addiu %0,%0,%%lo(D_'+addr+')" : "+r"(source));', 'source+=(s32)(s16)0x'+addr[-4:]+';')
(out/'sa_copy_b20_high.cpp').write_text(b)
