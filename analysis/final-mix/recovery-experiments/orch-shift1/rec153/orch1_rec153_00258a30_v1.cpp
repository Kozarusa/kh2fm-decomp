#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 D_0035f07c;
extern "C" s32 D_0035f078;
bool func_00258a30() {
    bool result = false;
    if (D_0035f07c != 0) result = func_00139d78(D_0035f07c) != 0;
    if (!result && D_0035f078 != 0) result = func_00139d78(D_0035f078) != 0;
    return result;
}
