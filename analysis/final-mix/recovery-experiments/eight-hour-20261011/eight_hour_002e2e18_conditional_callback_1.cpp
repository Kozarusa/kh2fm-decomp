#include "../common/types.h"
extern "C" u32 D_00361f60;
extern "C" void func_002ceb08(void);
u32 func_002e2e18(void)
{
 register u32 saved asm("$16")=D_00361f60;
 asm("" : "+r"(saved));
 if(saved!=0)func_002ceb08();
 return *(u32*)(saved+264);
}
