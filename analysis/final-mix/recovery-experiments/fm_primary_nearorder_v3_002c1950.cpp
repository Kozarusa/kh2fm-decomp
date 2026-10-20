#include "../common/types.h"
extern "C" void func_0017f488(f32, f32, s32, u32);
extern "C" s64 func_00180cd0(s32);
extern "C" s64 func_001805a8(s32, s32);
extern "C" void func_00169f98(u32);
extern "C" void func_0016bd60(u32, s32);
extern "C" void func_001c1fe0(u32, s32);
extern "C" void func_002c5fa0(u32);
extern "C" void func_002eb6f8(f32, u32, s32);
extern f32 D_0036dd70, D_003754e8, D_00375e98;
typedef u32 (*FmAnimationVirtual)(u32);

// Narrow original-instruction scheduling proposal; exact proof required.

void func_002c1950(u64 unused, u32 object) {
    register f32* speedAddress asm("$15");
    asm("lui %0,%%hi(D_003754e8); addiu %0,%0,%%lo(D_003754e8)" : "=r"(speedAddress));
    func_0017f488(*speedAddress, 0.0f, (s32)object + 0x140, 0);
    func_002c5fa0(object);
}
