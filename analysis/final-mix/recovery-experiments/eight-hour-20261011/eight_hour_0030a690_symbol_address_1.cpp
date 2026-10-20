#include "../common/types.h"
extern "C" u32 D_00366164;
extern "C" u8 D_01e389a8;
extern "C" void func_002fde18(u8*,u32,u32);
u32 func_0030a690(void)
{
 register u32 address asm("$2")=0x00360000;
 asm("" : "+r"(address));
 *(u32*)(address+0x6164)=0;
 func_002fde18(&D_01e389a8,0,4);
 return 0;
}
