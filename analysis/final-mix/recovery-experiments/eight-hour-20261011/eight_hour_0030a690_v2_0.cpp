#include "../common/types.h"
extern "C" void func_002fde18(u8*,u32,u32);
u32 func_0030a690(void)
{
 register u32 address asm("$2")=0x00360000;
 register u32 callback asm("$4")=0x01e40000;
 asm("" : "+r"(address),"+r"(callback));
 *(u32*)(address+0x6164)=0;
 func_002fde18((u8*)(callback-30296),0,4);
 return 0;
}
