#include "../common/types.h"
extern "C" f32 D_0036e3c8;
extern "C" void func_001a5990(f32,u64,u64);
void func_001d29a0(u64 a,u64 b) { register f32* address asm("$15")=&D_0036e3c8;asm("" : "+r"(address));register f32 value asm("$f12")=*address;asm("" : "+f"(value) :: "memory");func_001a5990(value,b,0); }
