#include "../common/types.h"
extern "C" u32 D_0035f028;
extern "C" void func_00139d78(u32);
void func_00256b80(s32 index)
{
 register s32 stride asm("$15")=408;
 asm("" : "+r"(stride));
 register s32 offset asm("$13")=index*stride;
 asm("" : "+r"(offset));
 func_00139d78(D_0035f028+offset);
}
