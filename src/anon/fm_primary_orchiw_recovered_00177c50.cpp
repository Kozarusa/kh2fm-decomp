#include "../common/types.h"
extern "C" u64 func_001a1de0(u32);
extern "C" s32 func_00177860(s32);
extern "C" u64 func_00187650(...);
extern "C" s32 func_00187520(u8*, s32, s32, u8);

s32 func_00177c50(u8* object, s32 amount, s32 mode, u8 flag) {
    if (*(u32*)(object + 0x48c) != 0) {
        if (func_001a1de0(*(u32*)(object + 0x48c)) == 0 && amount < 0) {
            f32 ratio = (f32)(-amount) / (f32)*(s32*)(*(u8**)(object + 0x48c) + 4);
            s32 entry = func_00177860((s32)object);
            s32 count = (s32)(ratio * *(f32*)(entry + 0x58));
            if (count > 0) {
                func_00187650(object, count, 0);
            }
        }
    }
    if ((*(u32*)(object + 0x160) & 0x4000) != 0) {
        flag = 0;
    }
    return func_00187520(object, amount, mode, flag);
}
