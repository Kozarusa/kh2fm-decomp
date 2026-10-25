#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" s32 func_0017ec98(...);
extern "C" s32 func_0017edf0(s32*, s32);
extern "C" u32 func_00180408(u32, u8*);
extern "C" f32 func_002f8b00(f32, f32);

f32 func_00180448(s32* object, s32 index, f32 value, f32 fallback) {
    if ((u32)(object[5] - 1U) < 2 && (u32)(index - 1U) < 2) {
        f32 ratio = ((*(f32*)((u8*)object + 48) + D_00349e10) + value) / *(f32*)((u8*)object + 44);
        s32 found = func_0017ec98(object, index);
        s32 selected = func_0017edf0(object, found);
        u8* pointer = (u8*)func_00180408((u32)object, (u8*)selected);
        s32 count = ((s32 (*)(u8*))(*(u32*)(*(u32*)pointer + 8)))(pointer);
        return func_002f8b00((f32)count * ratio, (f32)count);
    }
    return fallback;
}
