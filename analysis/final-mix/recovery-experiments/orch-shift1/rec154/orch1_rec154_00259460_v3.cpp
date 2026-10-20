#include "../common/types.h"
extern "C" s16 D_00372b50[];
s32 func_00259460(s32 value, u8 flag) {
    register s32 result asm("$2") = 11; // why: original default return value lives in v0 during scan
    if (D_00372b50[0] >= 0) {
        s16* pointer = D_00372b50;
        do {
            if (*pointer == value) {
                if (flag != 0) return pointer[2];
                return pointer[1];
            }
            pointer += 3;
        } while (*pointer >= 0);
    }
    return result;
}

