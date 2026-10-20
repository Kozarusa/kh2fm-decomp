#include "../common/types.h"

s32 func_002811f8(s16* table, s32 key) {
    s32 count = *(s32*)table;
    s32 index;
    s32 result;
    if (count > 0) {
        index = 0;
        table += 2;
        do {
            s16 value = *table;
            if (value == key) {
                break;
            }
            table += 10;
            index++;
        } while (index < count);
    }
    result = -1;
    if (index < count) {
        result = index;
    }
    return result;
}