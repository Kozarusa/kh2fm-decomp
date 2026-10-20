#include "../common/types.h"
extern "C" s8* D_0035f5d0;
extern "C" int func_002a01c8(int);
extern "C" s32 func_002943e8(s32);
s32 func_002a00f0() {
    s32 index = 0;
    s32 count = 0;
    if (*D_0035f5d0 > 0) {
        do {
            s32 value = func_002a01c8(D_0035f5d0[index + 6]);
            ++index;
            if (func_002943e8(value)) ++count;
        } while (index < *D_0035f5d0);
    }
    return count;
}
