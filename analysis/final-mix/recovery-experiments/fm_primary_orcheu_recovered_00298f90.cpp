#include "../common/types.h"
extern "C" u8 D_0035f5a2;
extern "C" u32 D_0035f59c;
extern "C" u32 func_0023f900(u32);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00293d80(s32);

u32 func_00298f90() {
    if (D_0035f5a2 != 0 && func_0023f900(D_0035f59c) != 0) {
        func_0023fad0(D_0035f59c);
    }
    u32 result = func_00293d80(5101);
    D_0035f5a2 = 0;
    return result;
}
