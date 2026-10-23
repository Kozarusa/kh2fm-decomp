#include "../common/types.h"

u8 func_001560a8(u8* object, s32* remainder, s32* step) {
    u8* entry = *(u8**)(*(u8**)(object + 0x34) + 0x48c);
    u8 count = entry[0x1b3];
    f32 total = *(f32*)(entry + 0x1b4);
    s32 size = (s32)(*(f32*)(entry + 0x1b8) / (f32)count);
    *step = size;
    if (size == 0) {
        *remainder = 0;
        return 0;
    }
    s32 value = (s32)total;
    u32 index = value / size;
    if (index == count) {
        *remainder = size;
        index = index - 1;
    } else {
        *remainder = value % size;
    }
    return index;
}
