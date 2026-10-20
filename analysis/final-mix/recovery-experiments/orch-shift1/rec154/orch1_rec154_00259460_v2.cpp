#include "../common/types.h"
extern "C" volatile s16 D_00372b50[];
s32 func_00259460(s32 value, u8 flag) {
    s32 result = 11;
    if (D_00372b50[0] >= 0) {
        volatile s16* pointer = D_00372b50;
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

