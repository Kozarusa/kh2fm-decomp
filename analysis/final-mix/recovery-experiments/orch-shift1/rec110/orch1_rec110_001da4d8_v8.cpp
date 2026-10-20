#include "../common/types.h"

s32 func_001da4d8(s32* object, u16 mode) {
    s32 kind = mode >> 6;
    s32 result = object[0];
    u32 word = *(u16*)(object[1] * 2 + result + 0x10);
    object[1] = object[1] + 1;
    if (kind != 1) {
        if (kind < 2) {
            if (kind != 0) {
                result = 0;
            } else {
                result = object[2];
            }
        } else if (kind != 2) {
            if (kind == 3) {
                result = result + 0x10;
                word = word << 1;
            } else {
                result = 0;
            }
        } else {
            result = *(s32*)object[2];
        }
    } else {
        result = object[4];
    }
    return result + word;
}
