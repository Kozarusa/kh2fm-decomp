#include "../common/types.h"

u8* func_0018a100(s32* table, u32 key, u8* start) {
    u8* result = (u8*)(table + 16);
    if (start != 0) {
        result = start + 20;
    }
    u8* end = (u8*)(table + 16) + *table * 20;
    for (;;) {
        if (result >= end) {
            return 0;
        }
        if (key == 22) {
            break;
        }
        if (result[4] == key) {
            break;
        }
        result += 20;
    }
    return result;
}