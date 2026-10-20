#include "../common/types.h"

s32 func_00195468(s32 table, s32 key) {
    s16* cursor = (s16*)(table + 8);
    s32 result = 0;
    for (;;) {
        s16 entry = *cursor;
        cursor++;
        if (entry == key) {
            return result;
        }
        if (result + 1 > 255) {
            break;
        }
        result++;
    }
    return -1;
}