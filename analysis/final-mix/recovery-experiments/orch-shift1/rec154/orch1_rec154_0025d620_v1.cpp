#include "../common/types.h"
extern "C" u32 func_00253578(...);
extern "C" u32 func_00287bc0(...);
s32 func_0025d620(u32 value) {
    s32 result = 1;
    s32 mode = func_00287bc0();
    if (mode != 1) {
        if (mode < 2) {
            if (mode != 0) return 0;
            if (value == 0) return result;
            if (func_00253578() == 0) return result;
            return 0;
        }
        if (mode != 12) return 0;
    }
    return 1;
}
