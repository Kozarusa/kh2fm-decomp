#include "../common/types.h"
extern "C" s16 D_00372b50[];

s32 func_00259460(s32 value, u8 flag) {
    s32 result = 11;
    s32 index = 0;
    if (D_00372b50[0] >= 0) {
        do {
            if (D_00372b50[index * 3] == value) {
                if (flag != 0) result = D_00372b50[index * 3 + 2];
                else result = D_00372b50[index * 3 + 1];
                break;
            }
            index++;
        } while (D_00372b50[index * 3] >= 0);
    }
    return result;
}
