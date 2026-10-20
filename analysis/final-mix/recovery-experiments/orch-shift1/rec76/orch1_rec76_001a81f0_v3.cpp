#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a81f0(u32 a, u32 b, u32 c) {
    u8* base = D_01c6cb98;
    s32 index;
    u8* entry;
    s32 count;
    for (index = 0, entry = base + 4, count = *(u16*)(base + 2); count != 0 && index < count; index++, entry += 12) {
        if (entry[4] == 0 && entry[5] == a && entry[6] == b && entry[7] == c) {
            return entry;
        }
    }
    return 0;
}