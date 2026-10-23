#include "../common/types.h"
extern "C" f32 func_002e50f8(u32);
extern "C" f32 D_00375db8;

f32 func_002dd218(u32 object)
{
 f32 value=func_002e50f8(object+256);
 register f32* bias asm("$15")=&D_00375db8;
 asm("" : "+r"(bias));
 return -(value+*bias);
}
