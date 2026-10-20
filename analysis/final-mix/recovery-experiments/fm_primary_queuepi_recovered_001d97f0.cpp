#include "../common/types.h"
extern "C" u16 D_0032fafe[];

void func_001d97f0(u32 index)
{
 register u16* base asm("$15")=D_0032fafe;
 register u16* slots asm("$4")=(u16*)(index*2+(u32)base);
 asm("" : "+r"(slots));
 register u32 count asm("$14")=slots[3];
 register u32 next asm("$15")=count+1;
 asm("" : "+r"(count) : "r"(next));
 if((u16)count<999)slots[3]=(u16)next;
}
