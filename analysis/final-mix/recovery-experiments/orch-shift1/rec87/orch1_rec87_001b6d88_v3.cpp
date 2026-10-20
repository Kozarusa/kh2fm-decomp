#include "../common/types.h"

void func_001b6d88(u8* object, s32 state) {
    if (state == 3) {
        u8 value = *(volatile u8*)object;
        if (value >= 3) {
            object[0] = value + 1;
            return;
        }
    }
    object[0] = state;
    if (state == 2) {
        object[3] = object[3] & 0xfe;
    }
}

