#include "../common/types.h"
extern "C" u32 func_00105c30(void);
extern "C" s32 D_0035ecac;
extern "C" s32 D_0035ecb0;
extern "C" s32 D_0035ecb4;
extern "C" s32 D_01dae6a0;
s32 func_002402e0() {
    s32 result = func_00105c30();
    s32 value;
    if (result == 2) value = D_0035ecb0;
    else if (result < 3) {
        if (result == 1) value = D_0035ecac;
        else value = D_0035ecb4;
    } else if (result == 8) value = D_0035ecac;
    else value = D_0035ecb4;
    D_01dae6a0 = value;
    return D_01dae6a0;
}

