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
typedef u32 (*FmAnimationVirtual)(u32, s32);

void func_00171150(const u32* packet) {
    func_0017f488(*(const f32*)(packet + 2), 0.0f, (s32)packet[0] + 0x140, packet[1]);
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
        func_0017f488(D_0036dd70, 0.0f, (s32)object + 0x140, 0);
    } else {
        func_001c1fe0(object, 5);
    }
}

void func_002c1950(u64 unused, u32 object) {
    func_0017f488(D_003754e8, 0.0f, (s32)object + 0x140, 0);
    func_002c5fa0(object);
}

void func_002e0720(u32 object, s32 second) {
    FmAnimationVirtual call = *(FmAnimationVirtual*)(*(u32*)object + 0x2c);
    u32 result = call(object, second);
    func_0017f488(D_00375e98, 0.0f, second + 0x140, result);
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
    if (((*(u32*)(object + 0x160) & 4) != 0 ||
         ((*(u32*)(object + 0x160) & 0x10) != 0 && value != 0xfc)) &&
        *(s32*)(object + 0x154) != value)
        func_002eb6f8(incoming, object, value);
}
