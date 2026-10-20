#include "../common/types.h"

s32 func_002811f8(s16* table, s32 key) {
    s32 count = *(s32*)table;
    s16 value;
    s32 index = 0;
    table += 2;
    if (count > 0) {
        value = *table;
        while (value != key) {
            table += 10;
            index++;
            if (index >= count) {
                break;
            }
            value = *table;
        }
    }
    return (index < count) ? index : -1;
}