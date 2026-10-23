#include "../common/types.h"
extern "C" u32 func_00136b78(...);
extern "C" u32 func_00225540(void);
extern "C" s32 D_01dad910[2];

u32 func_002252b0(void) {
    u32 result = func_00225540();
    if (result != 0) {
        if (D_01dad910[0] != -1) result = func_00136b78(0, D_01dad910[0]);
        if (D_01dad910[1] != -1) return func_00136b78(1, D_01dad910[1]);
    }
    return result;
}
