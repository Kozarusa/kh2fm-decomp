#include "../common/types.h"
extern "C" s16 D_00372b50[];
s32 func_00259460(s32 value, u8 flag) {
    register s32 result asm("$2") = 11; // why: original default return value lives in v0 during scan
    if (D_00372b50[0] >= 0) {
        s32 index = 0;
        do {
            if (D_00372b50[index] == value) {
                if (flag != 0) return D_00372b50[index + 2];
                return D_00372b50[index + 1];
            }
            index += 3;
        } while (D_00372b50[index] >= 0);
    }
    return result;
}


