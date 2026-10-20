#include "../common/types.h"
extern "C" void func_0017f488(f32,f32,s32,u32);
extern "C" void func_002c5fa0(u32);
extern f32 D_003754e8;
void func_002c1950(u64 unused,u32 object) {
 register f32 *speedAddress asm("$15")=&D_003754e8; asm volatile("" : "+r"(speedAddress));
 func_0017f488(*speedAddress,0.0f,(s32)object+0x140,0);
 func_002c5fa0(object);
}
