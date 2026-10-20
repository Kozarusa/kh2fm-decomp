#include "../common/types.h"
extern "C" u32 func_00256b68(s32);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028be58(...);
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f04c;
u32 func_00262290() {
    u32 result = func_00139d78(func_00256b68(1));
    if (result != 0) return result;
    if (D_0035f01c != 0) result = func_0028acc8(D_0035f01c) != 0;
    if (result == 0 && D_0035f04c != 0) result = func_0028be58(D_0035f04c) != 0;
    return result;
}
