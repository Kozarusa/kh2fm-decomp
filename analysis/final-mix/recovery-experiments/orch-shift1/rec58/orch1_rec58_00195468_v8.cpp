#include "../common/types.h"

s32 func_00195468(s32 table, s32 key) {
    s16* cursor = (s16*)(table + 8);
    // why: original keeps the loop index in t5 ($13)
    register s32 index asm("$13") = 0;
    // why: original keeps the result in v0 ($2)
    register s32 result asm("$2");
    s32 more;
    do {
        // why: original loads the entry into t7 ($15)
        register s32 entry asm("$15") = *cursor;
        result = index;
        index++;
        cursor++;
        more = index < 256;
        if (entry == key) {
            return result;
        }
    } while (more);
    result = -1;
    return result;
}