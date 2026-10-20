from pathlib import Path
out=Path(__file__).parent
for variant in (3,4):
 for addr in ('00114438','00114490'):
  s=(out/f'sa_lookup_table_v0_{addr}.cpp').read_text()
  s=s.replace('register u32 base asm("$10"); asm("addu %0,%1,%2" : "=r"(base) : "r"(root),"r"(relative));','register u32 base asm("$10")=root+relative; asm("" : "+r"(base));')
  if variant==4:
   s=s.replace(' if(root)', ' register s32* empty asm("$2")=0; asm("" : "+r"(empty));\n if(root)').replace(' return 0;', ' return empty;')
  (out/f'sa_lookup_table_v{variant}_{addr}.cpp').write_text(s)
for variant in (0,1):
 s='''#include "../common/types.h"
s32* func_00124c48(u32 object,s32 value) {
 register u32 root asm("$14")=*(u32*)(object+4);
 register s32* item asm("$2")=0;
 if(*(s32*)(root+12)) item=(s32*)(root+*(u32*)(root+8));
 asm("" : "+r"(item));
 if(item) {
 register s32 key asm("$12")=*item; asm("" : "+r"(key));
 if(key==-1) return 0;
 register s32 sentinel asm("$11")=-1; asm("" : "+r"(sentinel));
 do {
 if(key==value) { asm volatile("" : : "r"(item) : "memory"); return item; }
 register u32 base asm("$13")=(u32)item+16;
 register u32 offset asm("$15")=((u32*)item)[1]<<4;
 item=(s32*)(base+offset);
 register s32 next asm("$14")=*item; asm("" : "+r"(next));
 key=next;
 } while(key!=sentinel);
 }
 return 0;
}
'''
 if variant==1:s=s.replace('register u32 base asm("$13")=(u32)item+16;', 'register u32 base asm("$13")=(u32)item+16; asm("" : "+r"(base));')
 (out/f'sa_lookup_sentinel_v{variant}_00124c48.cpp').write_text(s)
