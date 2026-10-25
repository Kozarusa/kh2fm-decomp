#include "../common/types.h"
extern "C" f32 D_00375b14;
extern "C" f32 D_00375b18;
extern "C" s32 func_002d5578(u8*);
extern "C" s32 func_00178d28(u8*);
extern "C" void func_0017f488(f32, f32, u8*, u32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32); // copied from accepted caller fm_primary_orchfj_recovered_002c17d8.cpp

s32 func_002d54a8(u8* object) {
    s32 result = func_002d5578(object);
    if (result == 0 || (*(u32*)(object + 0x160) & 0x10) != 0) {
        if (*(f32*)(object + 0xc2c) == 0.0f) {
            f32* source;
            if (*(f32*)(object + 0x550) >= 0.0f) {
                source = &D_00375b14;
            } else {
                source = &D_00375b18;
            }
            *(f32*)(object + 0xc20) = *source;
        }
        result = func_00178d28(object);
        u8* motion = *(u8**)(object + 0xc18);
        if (motion != 0) {
            func_0017f488(0.0f, 0.0f, motion + 0x140, 0x97);
            return func_0017f5e0(*(u8**)(object + 0xc18) + 0x140, 0, 0, 0.0f, 0.0f);
        }
    }
    return result;
}
