#include "../common/types.h"
extern "C" s32 D_0034a400;
extern "C" u32 D_0034a408[];
extern "C" s32 func_0014ecf8(s32);
extern "C" s32 func_00136958();
extern "C" u32 func_002bc2e8(u32, u32, u32);

void func_0014ed28(s32 object, u32 extra) {
    s32 handle = func_0014ecf8(object);
    if (handle != 0) {
        u32* slot = &D_0034a408[D_0034a400];
        *slot = func_002bc2e8(handle, func_00136958(), extra);
        D_0034a400 = D_0034a400 + 1;
    }
}
