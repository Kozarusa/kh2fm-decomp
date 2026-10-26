#include "../common/types.h"

extern "C" u32 func_0017df58(s32);
extern "C" u32 func_0019baa8(s32);

u32 func_001c9df8() {
    for (s32 i = 0; i < 2; i++) {
        u32 value = func_0017df58(i);
        if (value && func_0019baa8(value)) {
            return 1;
        }
    }
    return 0;
}
