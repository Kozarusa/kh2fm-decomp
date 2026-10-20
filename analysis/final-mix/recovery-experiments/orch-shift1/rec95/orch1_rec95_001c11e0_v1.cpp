#include "../common/types.h"
extern "C" u8 D_01d49388[];

u16* func_001c11e0() {
    s32 count = 5;
    u16* pointer = (u16*)(D_01d49388 + 320);
    do {
        if (*pointer != 0) {
            return pointer;
        }
        pointer = (u16*)((u8*)pointer - 64);
        count--;
    } while (count > 0);
    return 0;
}
