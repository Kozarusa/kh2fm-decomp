#include "../common/types.h"
extern "C" u16 D_0032fafe[];
void func_001d97c8(void)
{
 register u16* slots asm("$14")=D_0032fafe;asm("" : "+r"(slots));
 register u32 count asm("$15")=slots[1];
 register u32 next asm("$13")=count+1;
 asm("" : "+r"(count) : "r"(next));
 if((u16)count<999)slots[1]=(u16)next;
}
