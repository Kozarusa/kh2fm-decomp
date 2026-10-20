#include "../common/types.h"
extern "C" void func_0017f488(f32,f32,s32,u32);
extern "C" void func_002c5fa0(u32);
extern f32 D_003754e8;
// Original split address and float-zero lifetime; low address is 0x54e8.
void func_002c1950(u64 unused,u32 object) {
 register f32 zero asm("$f13")=0.0f;
 asm volatile("" : "+f"(zero));
 register f32 *speedAddress asm("$15");
 asm volatile("lui %0,0x37" : "=r"(speedAddress) : "f"(zero));
 speedAddress=(f32*)((u32)speedAddress+0x54e8);
 asm("" : "+r"(speedAddress));
 func_0017f488(*speedAddress,zero,(s32)object+0x140,0);
 func_002c5fa0(object);
}
