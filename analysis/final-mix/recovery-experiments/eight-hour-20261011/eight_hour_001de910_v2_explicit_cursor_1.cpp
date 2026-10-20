#include "../common/types.h"
extern "C" void func_001de690(s32);
extern "C" void func_001dced0(void);
void func_001de910(void)
{
 func_001de690(0);
 register u32 high asm("$15")=0x01da0000;
 asm("" : "+r"(high));
 register u32* cursor asm("$14")=(u32*)(high-7352);
 asm("" : "+r"(cursor));
 *(u32*)(high-7352)=0;
 cursor[1]=0;
 func_001dced0();
}
