#include "../common/types.h"
extern "C" u32 D_0035f028;
extern "C" u32 func_00139d78(u32);
void func_00256b80(s32 index)
{
 register u32 high asm("$14")=0x00360000;
 register s32 stride asm("$15")=408;
 asm("" : "+r"(stride));
 asm("" : "+r"(high));
 register s32 offset asm("$13")=index*stride;
 u32 result=func_00139d78(*(u32*)(high-4056)+offset);
 asm("" : : "r"(result));
}
