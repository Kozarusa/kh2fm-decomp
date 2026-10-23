#include "../common/types.h"
extern "C" u8 D_01d49388[];

u16* func_001c11e0() {
    s32 count = 5;
    u8* base = D_01d49388;
    asm("" : "+r"(base)); // why: keeps the base address separate from the +320 offset
    u16* pointer = (u16*)(base + 320);
    do {
        if (*pointer != 0) {
            return pointer;
        }
        pointer = (u16*)((u8*)pointer - 64);
        count--;
    } while (count > 0);
    return 0;
}
