#include "../common/types.h"

extern "C" s32 func_00239870(u32);
extern "C" char D_003486b0;
extern "C" char D_00347e60;
extern "C" char D_00347f98;

s32 func_0031b7e8(u32* object) {
    s32 result;
    object[0] = (u32)(long)&D_003486b0;
    object[0x70] = (u32)(long)&D_00347e60;
    func_00239870((u32)(long)(object + 0x76));
    object[0] = (u32)(long)&D_00347e60;
    object[0x70] = (u32)(long)&D_00347f98;
    result = func_00239870((u32)(long)(object + 6));
    object[0] = (u32)(long)&D_00347f98;
    return result;
}
