#include "../common/types.h"
extern "C" s32 func_0018a550(u8*, s32);

u8* func_001b7998(s32* list, s32 key) {
    s32 index = 0;
    if (*list > 0) {
        u8* entry = (u8*)list + 16;
        do {
            if (func_0018a550(entry, key) != 0) {
                return entry;
            }
            index++;
            entry += 32;
        } while (index < *list);
    }
    return 0;
}
