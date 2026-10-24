#include "../common/types.h"
struct Table {
    s32 pad;
    s32 count;
};
extern "C" Table* D_01c940b4;

u8* func_001aff90(u32 first, u32 second) {
    s32 index;
    u8* entry = (u8*)D_01c940b4 + 8;
    for (index = 0; index < D_01c940b4->count; index++, entry += 14) {
        if (entry[0] == first && entry[1] == second) {
            return entry;
        }
    }
    return 0;
}
