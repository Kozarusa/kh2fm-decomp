#include "../common/types.h"

s32* func_001bfd60(s32* entry, s32 key) {
    s32* free_slot = 0;
    s32 index = 0;
    do {
        if (*entry == key) {
            return entry;
        }
        if (*entry == 0) {
            free_slot = entry;
        }
        index = index + 1;
        entry = entry + 4;
    } while (index < 8);
    *free_slot = key;
    return free_slot;
}
