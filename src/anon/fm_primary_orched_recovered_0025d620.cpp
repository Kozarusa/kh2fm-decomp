#include "../common/types.h"
extern "C" u32 func_00253578(...);
extern "C" u32 func_00287bc0(...);

s32 func_0025d620(u32 value) {
    s32 result = 1;
    s32 mode = func_00287bc0();
    switch (mode) {
    case 0:
        if (value != 0 && func_00253578() != 0) result = 0;
        break;
    case 1:
    case 12:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
