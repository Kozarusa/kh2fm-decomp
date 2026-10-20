#include "../common/types.h"
extern "C" s8 D_003743c0[];
s32 func_00285d18(s32 value) {
    s32 result = 0;
    s32 index = 0;
    if (D_003743c0[index] >= 0) {
        do {
            if (D_003743c0[index++] == value) return 1;
        } while (D_003743c0[index] >= 0);
    }
    return result;
}

