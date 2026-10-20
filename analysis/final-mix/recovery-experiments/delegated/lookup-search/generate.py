from pathlib import Path
out=Path(r'C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/delegated/lookup-search')
for variant in range(3):
 for addr,off,cnt in [('00114438',0xa4,0xa0),('00114490',0xb4,0xb0)]:
  predicate='*item==value' if variant==0 else '__builtin_expect(*item==value,0)'
  success='asm volatile("" : : "r"(item) : "memory"); return item;' if variant!=2 else 'register s32* answer asm("$2")=item; asm volatile("" : "+r"(answer)); return answer;'
  text=f'''#include "../common/types.h"
s32* func_{addr}(u32 object,s32 value) {{
 register u32 root asm("$14")=*(u32*)(object+8);
 if(root) {{
 register u32 relative asm("$15")=*(u32*)(root+{off}); asm("" : "+r"(relative));
 register s32 index asm("$12")=0;
 register s32 initial asm("$13")=*(s32*)(root+{cnt}); asm("" : "+r"(initial));
 if(initial>0) {{
 register u32 base asm("$10"); asm("addu %0,%1,%2" : "=r"(base) : "r"(root),"r"(relative));
 register s32 count asm("$11"); asm("daddu %0,%1,$0" : "=r"(count) : "r"(initial),"r"(base));
 do {{
 register u32 offset asm("$15")=index*0x80;
 register s32* item asm("$13"); asm("addu %0,%1,%2" : "=r"(item) : "r"(offset),"r"(base));
 ++index;
 if({predicate}) {{ {success} }}
 }} while(index<count);
 }}
 }}
 return 0;
}}
'''
  (out/f'sa_lookup_table_v{variant}_{addr}.cpp').write_text(text)
