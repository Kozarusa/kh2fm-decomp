#include "../common/types.h"
extern "C" f32 D_0036ac9c;
extern "C" void func_001374c8(f32,u32*,u64,u64,u64);
void func_001375f0(u32* object,u64 second,u64 third)
{
 register u32 high asm("$15")=0x370000;
 asm("" : "+r"(high));
 register f32* scale asm("$15");
 asm("addiu %0,%1,-21348" : "=r"(scale) : "r"(high));
 func_001374c8(*scale,object,79,second,third);
 object[0x146]=0;
}
