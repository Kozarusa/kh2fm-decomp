#include "../common/types.h"

void func_002e9b10(u8* object) {
    s32 limit = *(s32*)object;
    u32 value = object[4] + 1;
    object[4] = value;
    if ((s32)(value & 0xff) >= limit) {
        u32 next;
        do {
            asm("" : "+r"(value)); // why: raises the counter's allocation priority so it gets t6
            next = value - object[0];
            value = next;
        } while ((s32)(next & 0xff) >= limit);
        object[4] = next;
    }
}
