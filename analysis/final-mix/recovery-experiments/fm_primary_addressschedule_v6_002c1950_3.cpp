#include "../common/types.h"
extern "C" void func_0017f488(f32,f32,s32,u32);
extern "C" void func_002c5fa0(u32);
extern f32 D_003754e8;
// Address and float lifetime constraint experiment.
void func_002c1950(u64 unused,u32 object) { register f32 zero asm("$f13")=0.0f; register f32* address asm("$15")=&D_003754e8; asm volatile("" : "+r"(address) : "f"(zero) : "memory"); func_0017f488(*address,zero,(s32)object+0x140,0); func_002c5fa0(object); }
