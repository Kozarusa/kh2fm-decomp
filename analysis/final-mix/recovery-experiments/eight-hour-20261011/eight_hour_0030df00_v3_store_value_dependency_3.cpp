#include "../common/types.h"
extern "C" void func_002fde18(u32,u32,u32);
s32 func_0030df00()
{
 register u32 high asm("$2")=0x360000;
 register s32 disabled asm("$3")=-1;
 register u32 callback asm("$4")=0x1e40000;
 asm("" : "+r"(high),"+r"(disabled));
 asm("lui %0,0x1e4" : "=r"(callback) : "r"(high),"r"(disabled));
 callback-=29080;
 asm("" : "+r"(disabled) : "r"(callback),"r"(high));
 *(s32*)(high+0x6180)=disabled;
 func_002fde18(callback,0,4);
 return 0;
}
