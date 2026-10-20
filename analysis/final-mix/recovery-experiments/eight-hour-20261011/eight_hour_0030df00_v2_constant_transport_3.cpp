#include "../common/types.h"
extern "C" void func_002fde18(u32,u32,u32);
s32 func_0030df00()
{
 register u32 high asm("$2");
 asm("lui %0,0x36" : "=r"(high));
 register s32 disabled asm("$3");
 asm("addiu %0,$0,-1" : "=r"(disabled) : "r"(high));
 register u32 callback asm("$4")=0x1e40000;
 asm("" : "+r"(high),"+r"(disabled),"+r"(callback));
 callback-=29080;
 *(s32*)(high+0x6180)=disabled;
 func_002fde18(callback,0,4);
 return 0;
}
