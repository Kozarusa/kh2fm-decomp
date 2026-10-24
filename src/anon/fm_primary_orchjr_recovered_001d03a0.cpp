#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" u8* D_00352130;
extern "C" f32 D_0036e3bc;
extern "C" s32 func_00178758(u8*);
extern "C" u32 func_00180618(u8*);
extern "C" void func_001a1aa0(u8*, s32);
extern "C" void func_0017f488(u8*, u32, f32, f32);
extern "C" void func_0017f5e0(u8*, s32, f32, f32, void*);
extern "C" u32 func_00190128(void*);
extern "C" bool func_00197920(...);
extern "C" u32 func_00190878(...);
extern "C" s32 func_001bd418(...);
extern "C" u64 func_001d14a0(...);
extern "C" void func_001d0558(u8*);
extern "C" void func_001d2648(f32, s32*, s32);
extern "C" void func_001d2690(f32, s32*, s32);
extern "C" s32 func_001d2750(s32*);

s32 func_001d03a0(u8* object) {
    u8 target[32];
    func_00178758(object);
    f32 zero = 0.0f;
    if (zero < *(f32*)(object + 0xb68)) {
        u8* motion = object + 0x140;
        if (func_00180618(motion) != 0) {
            f32 timer = *(f32*)(object + 0xb6c) - D_00349e10;
            *(f32*)(object + 0xb6c) = timer;
            if (timer <= zero) {
                func_001a1aa0(*(u8**)(object + 0x48c), 1);
                *(f32*)(object + 0xb6c) = *(f32*)(object + 0xb6c) + *(f32*)(D_00352130 + 0xd4);
            }
        }
        f32 time = *(f32*)(object + 0xb68) - D_00349e10;
        *(f32*)(object + 0xb68) = time;
        if (time <= 0.0f) {
            *(f32*)(object + 0xb68) = 0.0f;
            func_0017f488(motion, 5, 0.0f, 0.0f);
            func_0017f5e0(motion, 0, 0.0f, 0.0f, 0);
        }
    }
    func_00190128(target);
    u8* info = *(u8**)(object + 0x48c);
    s32 full = info[0x1b1] >= info[0x1b2];
    if (full) {
        if (object[0xb70] == 0) {
            func_001d0558(object);
            func_001d2648(D_0036e3bc, (s32*)(object + 0xb74), 0xbbc3);
            func_001d2690(D_0036e3bc, (s32*)(object + 0xb74), 0xbbc4);
        }
        func_00190878(target, func_001d14a0(), 0);
        func_001bd418(*(s32*)(object + 0xb44), 1, 0x1c8, target, 1, 100);
    } else if (!func_00197920()) {
        func_00190878(target, object, 0);
        func_001bd418(*(s32*)(object + 0xb44), 1, 0x1c7, target, 1, 100);
    }
    return func_001d2750((s32*)(object + 0xb74));
}
