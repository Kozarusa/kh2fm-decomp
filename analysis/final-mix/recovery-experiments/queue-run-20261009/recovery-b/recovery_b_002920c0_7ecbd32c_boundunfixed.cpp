#include "../common/types.h"
extern "C" s32 func_002924d0(u64,u64);
extern "C" void func_00292520(u64,u32,u32);
void func_002920c0(u64 p,s32* out,u64 a,u64 b,s32 q) { s32 first=func_002924d0(p,a); s32 second=func_002924d0(p,b); u32 bound=*(u16*)(q+0x18e); asm("" : "+r"(bound)); *out=(bound-(u32)*(u8*)(first+7))+(u32)*(u8*)(second+7); func_00292520(p,*(u8*)(first+7),*(u8*)(second+7)); }
