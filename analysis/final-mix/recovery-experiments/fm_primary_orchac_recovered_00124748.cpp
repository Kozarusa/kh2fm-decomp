#include "../common/types.h"

u8* func_00124748(u32* object, s32 index) {
    u8* base = (u8*)object[1];
    u8* result = 0;
    for (s32* cursor = (s32*)(base + 0x10); *cursor != 0; cursor++) {
        index--;
        result = base + *cursor;
        if (index == -1) break;
    }
    return result;
}
