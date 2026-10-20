#include "../common/types.h"

s32 func_001d7f40(s32 *table, u32 key) {
    s32 count = table[0];
    // why: original keeps the index in t5
    register s32 index asm("$13") = 0;
    s32 result;
    u8 *entry = (u8*)(table + 1);
    if (count > 0) {
        do {
            // why: original loads the byte into t7
            register u8 item asm("$15") = *entry;
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