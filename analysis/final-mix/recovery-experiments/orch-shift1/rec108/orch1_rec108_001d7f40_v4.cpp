#include "../common/types.h"

s32 func_001d7f40(s32 *table, u32 key) {
    s32 count = table[0];
    u8 *entry = (u8*)(table + 1);
    s32 index;
    for (index = 0; index < count; index++) {
        u8 item = *entry;
        entry += 0x44;
        if (item == key) {
            break;
        }
    }
    if (index >= count) {
        index = -1;
    }
    return index;
}