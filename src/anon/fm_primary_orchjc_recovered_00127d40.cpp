#include "../common/types.h"
extern "C" u32 func_00127f40(...);
extern "C" u32 func_001316f0(...);

// Preserve original registry aliases.
u32 func_00127d40(u32 object) asm("_Z16wtarget_00127d40jjjj");

u32 func_00127d40(u32 object) {
    s32* state = (s32*)(object + 144);
    u32 result = 0;
    switch (*state) {
    case 0:
        func_00127f40(object, state);
        result = object;
        break;
    case 1:
        func_001316f0(object, state);
        result = object;
        break;
    }
    return result;
}
