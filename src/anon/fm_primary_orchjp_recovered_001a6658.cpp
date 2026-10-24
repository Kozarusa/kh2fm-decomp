#include "../common/types.h"
extern "C" u8 func_001a3570(...);
extern "C" u8* D_01c6cb28;
extern "C" u8 D_0032bae0;

u8* func_001a6658(s32 id) {
    u8* entry = D_01c6cb28;
    s32 count = *(s32*)(entry + 4);
    entry += 8;
    s32 index;
    u8* found;
    for (index = 0; index < count; index++) {
        if (entry[0] == id) {
            found = entry;
            goto search;
        }
        entry += 56;
    }
    found = 0;
search:
    u8* result = found;
    if (found == 0) {
        return 0;
    }
    s32 level = 0;
    if (*(u16*)(found + 36) != 0) {
        level = func_001a3570(*(u16*)(found + 36));
        if (level == 0) {
            return 0;
        }
    }
    u8* table = D_01c6cb28;
    u8* next = found + 56;
    u8 special = D_0032bae0;
    u8* end = table + *(s32*)(table + 4) * 56 + 8;
    while (next < end && next[0] == result[0] && next[1] <= level) {
        u8 flag = next[2];
        if (flag == 0 || flag == special) {
            result = next;
        }
        next += 56;
    }
    return result;
}
