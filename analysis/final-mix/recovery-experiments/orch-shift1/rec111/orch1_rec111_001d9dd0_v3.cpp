#include "../common/types.h"
struct Table {
    s32 pad;
    s32 count;
};
extern "C" Table* D_01d5baa8;

u8* func_001d9dd0(u32 a, u32 b, u32 c) {
    s32 index;
    u8* entry = (u8*)D_01d5baa8 + 8;
    for (index = 0; index < D_01d5baa8->count; index++, entry += 10) {
        if (entry[4] == a && entry[5] == b && entry[6] == c) {
            return entry;
        }
    }
    return 0;
}
