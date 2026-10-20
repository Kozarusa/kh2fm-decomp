#include "../common/types.h"
extern "C" u32 func_0019c090(...);
extern "C" bool func_001c0cd8(s32);

s32 func_001886d0(u8* object) {
    s32 result = 0;
    if (!func_001c0cd8(*(s32*)(*(s32*)(object + 136) + 4))) {
        if (func_0019c090(*(s32*)(*(s32*)(object + 136) + 4))) {
            return result;
        }
    }
    result = (*(u32*)(*(s32*)(*(s32*)(object + 136) + 4) + 352) & 0x200) < 1;
    return result;
}
