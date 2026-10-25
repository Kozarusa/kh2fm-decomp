#include "../common/types.h"
extern "C" s32 func_001064a8(s32);

f32 func_0023e700(void)
{
 s32 random=func_001064a8(20)+10;

 return (f32)random*60.0f;
}
