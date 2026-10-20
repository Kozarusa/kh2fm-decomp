#include "../common/types.h"
extern "C" s32 func_002924d0(u64,u64);
extern "C" void func_00292520(u64,u32,u32);
void func_00292148(u64 p,s32* out,u64 a,u64 b,s32 q) { s32 first=func_002924d0(p,a); s32 second=func_002924d0(p,b); register u32 bound asm("$15")=*(u16*)(q+0x188); asm("" : "+r"(bound) : : "memory"); *out=(bound-(u32)*(u8*)(first+4))+(u32)*(u8*)(second+4); func_00292520(p,*(u8*)(first+4),*(u8*)(second+4)); }
