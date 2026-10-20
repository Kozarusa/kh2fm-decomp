#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_002839f0(s32);
extern "C" u8* D_0035f2b8;

u32 func_00283618() {
    u32 result = func_00139d78(D_0035f2b8+0x354);
    if (result == 0) {
        result = func_00139d78(D_0035f2b8+0x1a0);
        if (result == 0) result = func_002839f0(1);
    }
    return result;
}
