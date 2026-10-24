#include "../common/types.h"
extern "C" u8* func_00168b88(s32, s32, s32, s32);
extern "C" u32 func_0017efa0(u8*, s32, f32, f32);
extern "C" u32 func_00180800(u8*, s32);

u32 func_00180058(u8* object, s32 key, s8* code, s32 value, s32 extra, s32* counter, f32 speed) {
    s32 index = 0;
    do {
        u8* entry = func_00168b88(key, -1, code[0] | (code[1] << 8) | (code[2] << 16) | (code[3] << 24), index);
        if (entry != 0 && *(s32*)(entry + 8) != 0) {
            *(s32*)(object + 0xf0) = value;
            *(s32*)(object + 0xfc) = extra;
            *(u32*)(object + 0x24) |= 4;
            *(s32*)(object + 0x100) = 0;
            func_0017efa0(object, *(s32*)(entry + 8), speed, 0.0f);
            u32 result = func_00180800(object, index);
            if (counter != 0) {
                *(s32*)(object + 0x148) = (s32)counter;
                *counter = *counter + 1;
            }
            return result;
        }
        index++;
    } while (index < 4);
    return func_0017efa0(object, 0, 0.0f, 0.0f);
}
