#include "../common/types.h"
extern "C" s32 func_00253b00();
extern "C" s32 func_00253b18();
extern "C" s32 func_00292a58();
extern "C" s32 D_0035f4c8, D_0035f4cc, D_0035f4c0, D_0035f4bc, D_0035f4d0;
extern "C" s16 D_0035f4e0, D_0035f4d8;
extern "C" s8 D_0035f4e2;

s32 func_00292870() {
    D_0035f4c8 = func_00253b00();
    D_0035f4cc = func_00253b18();
    s32 result = D_0035f4cc / D_0035f4c0;
    D_0035f4cc = 0;
    D_0035f4d8 = 0;
    D_0035f4e0 = 0;
    D_0035f4d0 = result;
    if (D_0035f4bc < result) D_0035f4d0 = D_0035f4bc;
    D_0035f4e2 = 0;
    return func_00292a58();
}
