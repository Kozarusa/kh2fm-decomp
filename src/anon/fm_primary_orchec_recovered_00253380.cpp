#include "../common/types.h"

extern "C" s16 D_003726b8[];

s32 func_00253380(s32 value) {
    s32 result = 0;
    s32 index = 0;
    if (D_003726b8[0] >= 0) {
        do {
            if (D_003726b8[index] == value) {
                result = 1;
                break;
            }
            index++;
        } while (D_003726b8[index] >= 0);
    }
    return result;
}
