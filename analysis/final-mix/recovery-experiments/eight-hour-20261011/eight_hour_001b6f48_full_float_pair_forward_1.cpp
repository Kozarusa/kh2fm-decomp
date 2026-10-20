#include "../common/types.h"
extern "C" f32 D_0036dac4;
extern "C" f32 D_0036dac8;
extern "C" u32* func_0017c870(f32,f32,u32*,u64,u64);
u32* func_001b6f48(u32* output,u64 second,u64 third)
{
 register f32* firstAddress asm("$15")=&D_0036dac4;
 asm("" : "+r"(firstAddress));
 register f32 first asm("$f12")=*firstAddress;
 asm("" : "+f"(first));
 register f32* secondAddress asm("$15")=&D_0036dac8;
 asm("" : "+r"(secondAddress));
 func_0017c870(first,*secondAddress,output,second,third);
 return output;
}
