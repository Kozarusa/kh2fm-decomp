#include "../common/types.h"
extern "C" f32 D_0036ac9c;
extern "C" void func_001374c8(f32,u32*,u64,u64,u64);
void func_001375f0(u32* object,u64 second,u64 third)
{
 register f32* scale asm("$15")=&D_0036ac9c;
 asm("" : "+r"(scale) : "m"(object[0x146]));
 func_001374c8(*scale,object,79,second,third);
 object[0x146]=0;
}
