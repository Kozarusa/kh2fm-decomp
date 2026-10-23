#include "../common/types.h"

extern "C" void func_00239870(u32);
extern "C" s32 func_0031a840(u32);
extern "C" char D_0034a568;
extern "C" char D_00347e60;
extern "C" char D_00347f98;

s32 func_0031c248(u32* object) {
    s32 result;
    u32* sub;
    object[0] = (u32)(long)&D_0034a568;
    object[0x8c] = (u32)(long)&D_00347e60;
    func_00239870((u32)(long)(object + 0x92));
    sub = object + 0xc;
    sub[0] = (u32)(long)&D_00347e60;
    object[0x8c] = (u32)(long)&D_00347f98;
    func_00239870((u32)(long)(object + 0x12));
    result = func_0031a840((u32)(long)sub);
    object[0] = (u32)(long)&D_00347f98;
    return result;
}
