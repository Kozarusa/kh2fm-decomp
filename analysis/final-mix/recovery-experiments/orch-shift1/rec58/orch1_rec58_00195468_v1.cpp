#include "../common/types.h"

s32 func_00195468(s32 table, s32 key) {
    s16* cursor = (s16*)(table + 8);
    s32 index = 0;
    do {
        s32 entry = *cursor;
        s32 found = index;
        cursor++;
        index++;
        if (entry == key) {
            return found;
        }
    } while (index < 256);
    return -1;
}