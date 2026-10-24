#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 D_0035f250;
extern "C" u32 D_0035f258;
extern "C" u32 D_0035f254;

u32 func_0027f2b0() {
    u32 result = func_00139d78(D_0035f250);
    if (!result) {
        result = func_00139d78(D_0035f258);
        if (!result) result = func_0028acc8(D_0035f254);
    }
    return result;
}
