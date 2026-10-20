#include "../common/types.h"

s32 func_00195468(s32 table, s32 key) {
    s16* cursor = (s16*)(table + 8);
    s32 index = 0;
    s32 result;
    do {
        result = index;
        s16 entry = *cursor;
        index++;
        cursor++;
        if (entry == key) {
            return result;
        }
    } while (index < 256);
    result = -1;
    return result;
}