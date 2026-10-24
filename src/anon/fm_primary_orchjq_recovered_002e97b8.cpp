#include "../common/types.h"
extern "C" u8* D_01e2bfa0;

u8* func_002e97b8(u8* start) {
    register u8* base asm("$9") = D_01e2bfa0; // why: original keeps the table base in t1
    u8* end = base + 0x780;
    u8* current = base;
    if (start != 0) {
        current = start + 0x40;
    }
    while (current < end) {
        s32 count = *(s32*)(base + 0x7f8);
        s32 index = 0;
        s32 slot = (s32)(current - base) >> 6;
        if (count > 0) {
            for (;;) {
                s32 entry = ((s32*)(base + 0x780))[index];
                if (entry == slot) {
                    current += 0x40;
                    break;
                }
                index++;
                if (index >= count) break;
            }
        }
        if (index == count) {
            return current;
        }
    }
    return 0;
}
