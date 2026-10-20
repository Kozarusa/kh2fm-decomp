#include "../common/types.h"
extern "C" f32 D_0036c524;
extern "C" f32 D_0036c528;
extern "C" u32* func_0017c870(f32,f32,u32*,u64,u64);
u32* func_0017c8f0(u32* output,u64 second,u64 third)
{
 register f32* firstAddress asm("$15")=&D_0036c524;
 u32* saved=output;
 asm("" : "+r"(firstAddress) : "r"(saved));
 register f32 first asm("$f12")=*firstAddress;
 register f32* secondAddress asm("$15")=&D_0036c528;
 asm("" : "+r"(secondAddress));
 func_0017c870(first,*secondAddress,output,second,third);
 return output;
}
