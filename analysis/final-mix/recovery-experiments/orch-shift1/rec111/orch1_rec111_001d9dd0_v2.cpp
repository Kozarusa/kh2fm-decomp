#include "../common/types.h"
struct Table {
    s32 pad;
    s32 count;
};
extern "C" Table* D_01d5baa8;

u8* func_001d9dd0(u32 a, u32 b, u32 c) {
    s32 index = 0;
    Table* table = D_01d5baa8;
    u8* entry = (u8*)table + 8;
    s32 first = table->count;
    if (first > 0) {
        s32 count = first;
        do {
            if (entry[4] == a && entry[5] == b && entry[6] == c) {
                return entry;
            }
            index++;
            entry += 10;
        } while (index < count);
    }
    return 0;
}

