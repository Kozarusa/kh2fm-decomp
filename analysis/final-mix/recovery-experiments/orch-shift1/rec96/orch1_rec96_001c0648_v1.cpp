#include "../common/types.h"
extern "C" u8* D_01d49358;

u8* func_001c0648(u32 key) {
    s32 index = 0;
    s32 count = *(s32*)(D_01d49358 + 4);
    u8* entry = D_01d49358 + 8;
    if (count > 0) {
        do {
            if (*entry == key) {
                return entry;
            }
            entry += 16;
            index++;
        } while (index < count);
    }
    return 0;
}
