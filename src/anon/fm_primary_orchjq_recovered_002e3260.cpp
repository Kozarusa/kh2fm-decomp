#include "../common/types.h"

u32* func_002e3260(u32* table, u32 key, u32 value) {
    u32* entry = table + 4;
    s32 index = 0;
    s32 count = (s32)table[2];
    if (count > 0) {
        do {
            if (key == 0) {
                goto found;
            }
            if (entry[0] == 0) {
                goto found;
            }
            if ((entry[0] & 0xffff0000) == (key & 0xffff0000)) {
                if (*(u16*)((u8*)entry + 4) == value) {
                    goto found;
                }
            }
            index++;
            entry += 8;
        } while (index < count);
    }
    entry = 0;
found:
    return entry;
}
