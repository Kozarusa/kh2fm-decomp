#include "../common/types.h"
extern "C" u32 func_00253578(...);
extern "C" u32 func_00287bc0(...);
s32 func_0025d620(u32 value) {
    register s32 result asm("$16") = 1; // why: original result lives in s0 across mode query
    s32 mode = func_00287bc0();
    if (mode != 1) {
        if (mode < 2) {
            if (mode == 0) {
                if (value != 0 && func_00253578() != 0) result = 0;
            } else result = 0;
        } else if (mode != 12) result = 0;
    }
    return result;
}

