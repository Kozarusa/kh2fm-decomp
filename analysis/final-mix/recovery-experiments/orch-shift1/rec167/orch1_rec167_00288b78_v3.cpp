#include "../common/types.h"
extern "C" u8 func_00103b38(...);
extern "C" s32 func_00287f30();
extern "C" u8 D_0035f348;
extern "C" s32 D_0035f350;
extern "C" s32 D_0035f34c;
s32 func_00288b78() {
    s32 result = func_00103b38();
    if (result) result = func_00287f30();
    u8 value = D_0035f348;
    if (value) D_0035f348 = value - 1;
    else {
        if (D_0035f350) D_0035f34c = D_0035f350;
        else D_0035f34c = 0;
        D_0035f350 = 0;
    }
    return result;
}


