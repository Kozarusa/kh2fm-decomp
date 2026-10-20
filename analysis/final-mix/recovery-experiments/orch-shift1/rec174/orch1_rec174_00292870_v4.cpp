#include "../common/types.h"
extern "C" s32 func_00253b00();
extern "C" s32 func_00253b18();
extern "C" s32 func_00292a58();
extern "C" s32 D_0035f4c8, D_0035f4cc, D_0035f4c0, D_0035f4bc, D_0035f4d0;
extern "C" s16 D_0035f4e0, D_0035f4d8;
extern "C" s8 D_0035f4e2;
s32 func_00292870() {
    D_0035f4c8 = func_00253b00();
    s32 value = func_00253b18();
    register s32* cursor asm("$13") = &D_0035f4cc; // why: original keeps the two-store address in t5
    *cursor = value;
    s32 result = value / D_0035f4c0;
    s32 limit = D_0035f4bc;
    *cursor = 0;
    D_0035f4e0 = 0;
    D_0035f4d8 = 0;
    if (limit < result) result = limit;
    D_0035f4e2 = 0;
    D_0035f4d0 = result;
    return func_00292a58();
}


