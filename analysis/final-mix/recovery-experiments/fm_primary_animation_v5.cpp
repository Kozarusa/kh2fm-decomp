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

void func_00198450(u32 object) {
    s32 animation = (s32)object + 0x140;
    if (func_00180cd0(animation) != 0 && func_001805a8(animation, 0) != 0)
        func_0017f488(0.0f, 0.0f, animation, 0);
    func_00169f98(object);
}

void func_001c1d90(u64 unused, u32 object) {
    if (*(s32*)(object + 0xaac) == 0) {
        // The original retains a1=5 for this helper as well as the other branch.
        func_0016bd60(object, 5);
        register f32* speedAddress asm("$15") = &D_0036dd70;
        asm("" : "+r"(speedAddress));
        func_0017f488(*speedAddress, 0.0f, (s32)object + 0x140, 0);
    } else {
        func_001c1fe0(object, 5);
    }
}

void func_002c1950(u64 unused, u32 object) {
    register f32* speedAddress asm("$15") = &D_003754e8;
    asm("" : "+r"(speedAddress));
    func_0017f488(*speedAddress, 0.0f, (s32)object + 0x140, 0);
    func_002c5fa0(object);
}

void func_002e0720(u32 object, s32 second) {
    FmAnimationVirtual call = *(FmAnimationVirtual*)(*(u32*)object + 0x2c);
    s32 destination = second + 0x140;
    u32 result = call(object);
    register f32* speedAddress asm("$15") = &D_00375e98;
    asm("" : "+r"(speedAddress));
    func_0017f488(*speedAddress, 0.0f, destination, result);
}

void func_002eb778(f32 incoming, u32 object, s32 value, u8 force) {
    if (force == 0) {
        u32 flags = *(u32*)(object + 0x160);
        bool permitted;
        if ((flags & 4) != 0 || (flags & 8) != 0 || (permitted = false, (flags & 0x10) != 0))
            permitted = true;
        s32 current;
        if (permitted) current = *(s32*)(object + 0x154);
        else {
            if ((flags & 0x10) == 0) return;
            current = *(s32*)(object + 0x154);
        }
        if (current == value) return;
    }
    func_002eb6f8(incoming, object, value);
}

void func_002eb9d8(f32 incoming, u64 unused, u32 object, s32 value) {
    register u32 callObject asm("$4") = object;
    register s32 callValue asm("$5") = value;
    asm("" : "+r"(callObject), "+r"(callValue));
    u32 flags = *(u32*)(callObject + 0x160);
    register u32 animation asm("$13") = callObject + 0x140;
    asm("" : "+r"(animation));
    if (((flags & 4) != 0 || ((flags & 0x10) != 0 && value != 0xfc)) &&
        *(s32*)(animation + 0x14) != callValue)
        func_002eb6f8(incoming, callObject, callValue);
}
