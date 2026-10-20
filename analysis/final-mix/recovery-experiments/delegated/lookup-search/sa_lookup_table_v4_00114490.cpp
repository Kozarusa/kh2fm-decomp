#include "../common/types.h"
s32* func_00114490(u32 object,s32 value) {
 register u32 root asm("$14")=*(u32*)(object+8);
 register s32* empty asm("$2")=0; asm("" : "+r"(empty));
 if(root) {
 register u32 relative asm("$15")=*(u32*)(root+180); asm("" : "+r"(relative));
 register s32 index asm("$12")=0;
 register s32 initial asm("$13")=*(s32*)(root+176); asm("" : "+r"(initial));
 if(initial>0) {
 register u32 base asm("$10")=root+relative; asm("" : "+r"(base));
 register s32 count asm("$11"); asm("daddu %0,%1,$0" : "=r"(count) : "r"(initial),"r"(base));
 do {
 register u32 offset asm("$15")=index*0x80;
 register s32* item asm("$13"); asm("addu %0,%1,%2" : "=r"(item) : "r"(offset),"r"(base));
 ++index;
 if(*item==value) { asm volatile("" : : "r"(item) : "memory"); return item; }
 } while(index<count);
 }
 }
 return empty;
}
