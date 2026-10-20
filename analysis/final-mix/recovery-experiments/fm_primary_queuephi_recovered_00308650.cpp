#include "../common/types.h"
extern "C" u32 D_01e357d4;
extern "C" u32 D_003660d8;
extern "C" void func_003061d0(u32);
extern "C" void func_00305350(u32,u32);

void func_00308650(void)
{
 func_003061d0(5);
 register u32 address asm("$3")=0x01e30000;
 asm("" : "+r"(address));
 func_00305350(5,*(u32*)(address+0x57d4));
 register u32 dest asm("$3")=0x00360000;
 asm("" : "+r"(dest));
 *(u32*)(dest+0x60d8)=0;
}
