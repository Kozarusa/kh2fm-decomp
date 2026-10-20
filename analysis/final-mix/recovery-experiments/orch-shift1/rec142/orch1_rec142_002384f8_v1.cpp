#include "../common/types.h"
s32 func_002384f8(u8* object, s32 index) {
    u16* entry = (u16*)(*(u8**)(object + 12) + index * 4);
    u8* cursor = *(u8**)(object + 8) + entry[0] * 20;
    s32 count = entry[1];
    if (count > 0) {
        u8* base = *(u8**)(object + 4);
        do {
            u8* item = base + *(s32*)(cursor + 16) * 44;
            cursor += 20;
            if (*(f32*)(item + 20) != 0.0f || *(f32*)(item + 24) != 0.0f) return 1;
        } while (--count > 0);
    }
    return 0;
}