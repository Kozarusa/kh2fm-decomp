from pathlib import Path
out=Path(__file__).parent
for variant in (2,3):
 s=(out/'sa_lookup_sentinel_v0_00124c48.cpp').read_text().replace('asm("" : "+r"(item));','asm volatile("" : "+r"(item));').replace('if(key==value) { asm volatile("" : : "r"(item) : "memory"); return item; }','if(key==value) return item;')
 if variant==3:s=s.replace('if(key==-1)', 'if(__builtin_expect(key==-1,1))')
 (out/f'sa_lookup_sentinel_v{variant}_00124c48.cpp').write_text(s)
for addr in ('00114438','00114490'):
 s=(out/f'sa_lookup_table_v4_{addr}.cpp').read_text()
 s=s.replace('register u32 base asm("$10")=root+relative; asm("" : "+r"(base));','register u32 base asm("$10"); asm("addu %0,%1,%2" : "=r"(base) : "r"(root),"r"(relative));')
 (out/f'sa_lookup_table_v5_{addr}.cpp').write_text(s)
