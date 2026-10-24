#include "../common/types.h"

s32 func_002e64e8(u8 type, u8 subtype, u8* table) {
    s32 index = 0;
    register s32 count asm("$15") = *(s32*)(table + 12); // why: original loads the count into t7
    u8* entry = table + 16;
    if (count > 0) {
        register s32 limit asm("$12") = count; // why: original copies the count into t4 for the loop test
        do {
            if (entry[0] == type) {
                if (entry[1] == subtype) {
                    return index;
                }
            }
            index++;
            entry += *(s32*)(entry + 12);
        } while (index < limit);
    }
    return -1;
}
