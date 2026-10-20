#include "../common/types.h"
extern "C" u16 D_0032fafe[];
void func_001d97c8(void)
{
 register u16* slots asm("$14")=D_0032fafe;asm("" : "+r"(slots));
 u16 count=slots[1];if(count<999)slots[1]=count+1;
}
