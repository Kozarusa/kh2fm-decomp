#include "../common/types.h"
extern "C" u32 func_002577b0(...);
// why: no argument register is set before the call; the only definition is an auto-lift placeholder
extern "C" u32 func_0027b528();
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028be58(...);
extern "C" u32 D_0035f04c;
extern "C" u32 D_0035f01c;

u32 func_0027a908(u8 flag) {
    u32 result = func_002577b0();
    if (result == 0) {
        if (flag != 0) result = func_0027b528();
        if (result == 0) {
            if (D_0035f04c != 0) result = func_0028be58(D_0035f04c) != 0;
            if (result == 0 && D_0035f01c != 0) result = func_0028acc8(D_0035f01c) != 0;
        }
    }
    return result;
}
