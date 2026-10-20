#include "../common/types.h"
extern "C" s8 D_003743c0[];
s32 func_00285d18(s32 value) {
    s32 result = 0;
    volatile s8* pointer = D_003743c0;
    if (*pointer >= 0) {
        do {
            if (*pointer++ == value) return 1;
        } while (*pointer >= 0);
    }
    return result;
}

