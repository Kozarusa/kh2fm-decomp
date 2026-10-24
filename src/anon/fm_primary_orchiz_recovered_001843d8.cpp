#include "../common/types.h"
extern "C" s32 func_001805a8(u8*, s32);
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" void func_0017f5e0(u8*, s32, f32, f32, void*);
extern "C" s32 func_0016bd60(u8*, s32);

s32 func_001843d8(u8* object) {
    u8* motion = object + 0x140;
    if ((*(u32*)(object + 0x168) & 0x10) == 0 && func_001805a8(motion, 5) != 0) {
        func_0017f488(motion, 5, 0.0f, 0.0f);
        func_0017f5e0(motion, 0, 0.0f, 0.0f, 0);
    }
    s32 result = func_0016bd60(object, 0);
    *(u32*)(object + 0x108) |= 0x8000000;
    return result;
}
