#include "../common/types.h"

s32 func_002811f8(s32* table, s32 key) {
    s32 count = *table;
    s32 index = 0;
    if (index < count) {
        s16 value;
        table += 1;
        value = *table;
        do {
            if (value == key) {
                break;
            }
            table += 5;
            index++;
            value = *table;
        } while (index < count);
    }
    return (index < count) ? index : -1;
}