#include "../common/types.h"

void func_001a1b30(u8* object, s32 amount) {
    u8 raw = object[0x1b1];
    u8 limit = object[0x1b2];
    s32 current = raw & 0xff;
    s32 remaining = current - amount;
    if (current == limit || current < amount) {
        object[0x1b0] = 0;
    }
    if (remaining < 0) {
        remaining = 0;
    }
    object[0x1b1] = remaining;
}
