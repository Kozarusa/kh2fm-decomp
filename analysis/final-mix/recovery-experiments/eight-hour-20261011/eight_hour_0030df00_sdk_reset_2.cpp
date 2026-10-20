#include "../common/types.h"
extern "C" s32 D_00366180;
extern "C" void func_002fde18(u32,u32,u32);
s32 func_0030df00()
{
 register u32 high asm("$2")=0x360000;
 asm("" : "+r"(high));
 *(s32*)(high+0x6180)=-1;
 register u32 callback asm("$4")=0x1e40000;
 asm("addiu %0,%0,-29080" : "+r"(callback) : "m"(*(s32*)(high+0x6180)));
 func_002fde18(callback,0,4);
 return 0;
}
