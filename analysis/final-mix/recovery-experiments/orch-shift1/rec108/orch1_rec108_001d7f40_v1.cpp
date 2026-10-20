#include "../common/types.h"

s32 func_001d7f40(s32 *table, u32 key) {
    s32 count = table[0];
    s32 index = 0;
    u8 *entry = (u8*)(table + 1);
    if (count > 0) {
        do {
            u8 item = *entry;
            s32 current = index;
            index++;
            entry += 0x44;
            if (item == key) {
                return current;
            }
        } while (index < count);
    }
    return -1;
}