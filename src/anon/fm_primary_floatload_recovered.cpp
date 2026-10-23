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

void func_00171150(const u32* packet) {
    register f32 zero asm("$f13") = 0.0f;
    asm("" : "+f"(zero));
    u32 object = *(const volatile u32*)packet;
    f32 speed = *(const volatile f32*)(packet + 2);
    asm volatile("" : : : "memory");
    func_0017f488(speed, zero, (s32)object + 0x140, *(const volatile u32*)(packet + 1));
}
