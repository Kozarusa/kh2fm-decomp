#include "../common/types.h"

u16* func_00320c18(s32* table, u32 key) {
    s32 index = 0;
    s32 count = table[1];
    u16* entry = (u16*)(table + 2);
    if (count > 0) {
        do {
            if (*entry == key) {
                return entry;
            }
            entry += 4;
            index++;
        } while (index < count);
    }
    return 0;
}
