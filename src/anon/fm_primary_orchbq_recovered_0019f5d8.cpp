#include "../common/types.h"

s32* func_0019f5d8(s32* entry, s32 first, s32 second) {
    s32* end = entry + 24;
    do {
        if (*entry == first && entry[1] == second) {
            return entry;
        }
        entry = entry + 3;
    } while ((s32)entry < (s32)end);
    return 0;
}
