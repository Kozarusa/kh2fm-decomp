#include "../common/types.h"

// Preserve original registry aliases.
s32 func_00195468(s32 table, s32 key) asm("_Z16ctarget_00195468jjjj");

s32 func_00195468(s32 table, s32 key) {
    s16* cursor = (s16*)(table + 8);
    // why: original keeps the loop index in t5 ($13)
    register s32 index asm("$13") = 0;
    // why: original keeps the result in v0 ($2)
    register s32 result asm("$2");
    do {
        result = index;
        // why: original loads the entry into t7 ($15)
        register s32 entry asm("$15") = *cursor;
        index++;
        cursor++;
        asm volatile("" : "+r"(cursor)); // why: C10d keeps cursor increment before the compare
        if (entry == key) {
            return result;
        }
    } while (index < 256);
    result = -1;
    return result;
}
