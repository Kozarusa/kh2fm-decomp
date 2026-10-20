#include "../common/types.h"

void func_001b6d88(u8* object, s32 state) {
    if (state == 3) {
        u8 value = *(volatile u8*)object;
        s32 next = value + 1;
        // why: keeps the increment ahead of the range compare
        asm volatile("" ::: "memory");
        if (value >= 3) {
            object[0] = next;
            return;
        }
    }
    object[0] = state;
    if (state == 2) {
        object[3] = object[3] & 0xfe;
    }
}
