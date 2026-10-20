#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a81f0(u32 a, u32 b, u32 c) {
    s32 index = 0;
    s32 count;
    u8* entry = D_01c6cb98;
    if ((count = *(u16*)(entry + 2)) != 0) {
        entry += 4;
        do {
            if (entry[4] == 0 && entry[5] == a && entry[6] == b && entry[7] == c) {
                return entry;
            }
            index++;
            entry += 12;
        } while (index < count);
    }
    return 0;
}