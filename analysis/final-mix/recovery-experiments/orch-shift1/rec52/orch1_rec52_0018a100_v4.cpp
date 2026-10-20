#include "../common/types.h"

u8* func_0018a100(s32* table, u32 key, u8* start) {
    u8* current = (u8*)(table + 16);
    if (start != 0) {
        current = start + 20;
    }
    u8* end = (u8*)(table + 16) + *table * 20;
    u8* result = current;
    if (current < end) {
        result = current;
        for (;;) {
            if (key == 22) {
                return result;
            }
            if (result[4] == key) {
                return result;
            }
            result += 20;
            if (result >= end) {
                break;
            }
        }
    }
    return 0;
}