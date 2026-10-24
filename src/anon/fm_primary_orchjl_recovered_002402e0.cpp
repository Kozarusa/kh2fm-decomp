#include "../common/types.h"
extern "C" u32 func_00105c30(void);
extern "C" s32 D_0035ecac;
extern "C" s32 D_0035ecb0;
extern "C" s32 D_0035ecb4;
extern "C" volatile s32 D_01dae6a0;

s32 func_002402e0() {
    switch ((s32)func_00105c30()) {
    case 1:
    case 8:
        D_01dae6a0 = D_0035ecac;
        break;
    case 2:
        D_01dae6a0 = D_0035ecb0;
        break;
    default:
        D_01dae6a0 = D_0035ecb4;
        break;
    }
    return D_01dae6a0;
}
