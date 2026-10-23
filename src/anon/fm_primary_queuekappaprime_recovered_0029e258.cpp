#include "../common/types.h"
extern "C" u32 func_002766d0();
extern "C" void func_0028dac8(u32,s32);

void func_0029e258(s32 index)
{
 u32 base=func_002766d0();
 register s32 stride asm("$15")=408;
 asm("" : "+r"(stride));
 s32 offset=(index+1)*stride;
 func_0028dac8(base+offset+0x4398,9);
}
