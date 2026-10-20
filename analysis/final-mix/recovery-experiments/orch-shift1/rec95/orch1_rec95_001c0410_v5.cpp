#include "../common/types.h"

void func_001c0410(u8* target, u8* source, u8* extra) {
    s32 count = 0;
    do {
        if (*(s32*)(target + 0x30) == 0) {
            *(s32*)(target + 0x30) = *(s32*)(source + 0x1c);
            asm volatile("" ::: "memory"); // why: keeps store order
            u16 half = *(u16*)(extra + 0x26);
            *(f32*)(target + 0x34) = (f32)half;
            return;
        }
        count++;
        target += 8;
    } while (count < 4);
}
