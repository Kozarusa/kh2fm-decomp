#include "../common/types.h"

u8* func_0018a100(s32* table, u32 key, u8* start) {
    u8* current = (u8*)(table + 16);
    if (start != 0) {
        current = start + 20;
    }
    for (;;) {
        if ((u8*)(table + 16) + *table * 20 <= current) {
            return 0;
        }
        if (key == 22) {
            break;
        }
        if (current[4] == key) {
            return current;
        }
        current += 20;
    }
    return current;
}