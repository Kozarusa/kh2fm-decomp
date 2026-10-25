#include "../common/types.h"
extern "C" u32 func_001780d8(...);
extern "C" s32 func_0016b740(...);
extern "C" s32* func_001c0d38(...);
extern "C" u64 func_0017fd30(...);
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);
extern "C" u32 func_0016bd60(u64,u64);
// why: accepted definition fm_primary_orchjm_recovered_00198860.cpp returns s32 (u8*, s32)
extern "C" s32 func_00198860(u8* object, s32 command);

s32 func_001cedc0(u8* object) {
    s32 child;

    func_001780d8(object);
    child = func_0016b740(0x654);
    *(s32*)(object + 0xb6c) = child;
    if (child != 0) {
        func_001c0d38(child, object, 0x4002, 0);
        func_0017fd30(object + 0x140, *(s32*)(object + 0xb6c) + 0x140);
    }
    func_0017f488(object + 0x140, 44, 0.0f, 0.0f);
    func_0017f5e0(object + 0x140, 0, 0, 0.0f, 0.0f);
    func_0016bd60((u64)object, 23);
    return func_00198860(object, 9);
}
