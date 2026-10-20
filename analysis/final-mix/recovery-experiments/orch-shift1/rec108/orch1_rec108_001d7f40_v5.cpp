#include "../common/types.h"

s32 func_001d7f40(s32 *table, u32 key) {
    s32 count = table[0];
    s32 index;
    s32 result;
    u8 *entry;
    if (count > 0) {
        index = 0;
        entry = (u8*)(table + 1);
        do {
            u8 item = *entry;
            result = index;
            index++;
            entry += 0x44;
            if (item == key) {
                return result;
            }
        } while (index < count);
    }
    result = -1;
    return result;
}