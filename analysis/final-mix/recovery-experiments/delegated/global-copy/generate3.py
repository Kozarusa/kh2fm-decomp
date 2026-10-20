from pathlib import Path
out=Path('Codex/analysis/final-mix/recovery-experiments/delegated/global-copy')
b=(out/'sa_copy_b20_memory.cpp').read_text().replace('if(source!=destination)', 'if(destination!=source)')
b=b.replace('asm("lui %0,%%hi(D_0034a9c0)" : "=r"(source));', 'asm("lui %0,%%hi(D_0034a9c0)" : "=r"(source) : "m"(*(f32 *)(object+0x48)));')
(out/'sa_copy_b20_order.cpp').write_text(b)
