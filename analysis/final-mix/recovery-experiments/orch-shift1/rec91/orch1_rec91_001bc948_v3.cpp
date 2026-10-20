#include "../common/types.h"

u32 func_001bc948(u8* object) {
    s32 count = *(s32*)(object + 8);
    s32 index = 0;
    if (count > 0) {
        u8* entry = object + 17;
        do {
            u8 below = *entry < 4;
            if (below) {
                return 1;
            }
            entry += 12;
            index++;
        } while (index < count);
    }
    return 0;
}
