#include "../common/types.h"
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
 register u32 base asm("$13")=(u32)item+16; asm("" : "+r"(base));
 register u32 offset asm("$15")=((u32*)item)[1]<<4;
 item=(s32*)(base+offset);
 register s32 next asm("$14")=*item; asm("" : "+r"(next));
 key=next;
 } while(key!=sentinel);
 }
 return 0;
}
