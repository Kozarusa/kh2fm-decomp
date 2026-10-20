#include "../common/types.h"
extern "C" u8* D_01c6cb98;

u8* func_001a8258(u32 id) {
    s32 index = 0;
    u8* entry = D_01c6cb98 + 4;
    if (*(u16*)(D_01c6cb98 + 2) != 0) {
        do {
            if (entry[4] == 1 && *(u16*)entry == id) {
                return entry;
            }
            index++;
            entry += 12;
        } while (index < *(u16*)(D_01c6cb98 + 2));
    }
    return 0;
}