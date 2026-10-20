#include "../common/types.h"
extern "C" s32 func_001064a8(s32);
extern "C" f32 D_00371560;

f32 func_0023e700(void)
{
 s32 random=func_001064a8(20)+10;
 register f32* scale asm("$15")=&D_00371560;
 asm("" : "+r"(scale));
 return (f32)random**scale;
}
