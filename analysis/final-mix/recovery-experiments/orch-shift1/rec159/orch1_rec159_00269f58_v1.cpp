#include "../common/types.h"
extern "C" u32 func_00257780();
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028be58(...);
extern "C" u32 D_0035f04c;
extern "C" u32 D_0035f01c;
u32 func_00269f58() {
    u32 result = func_00257780();
    if (result == 0) {
        if (D_0035f04c != 0) result = func_0028be58(D_0035f04c) != 0;
        if (result == 0 && D_0035f01c != 0) result = func_0028acc8(D_0035f01c) != 0;
    }
    return result;
}
