#include "../common/types.h"
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001a8190(s32);
u32 func_002924d0(u32 object, u64 value) {
    u32 result = object + 11068;
    if (value != 0) {
        result = func_001a8190(func_001a80c8(value));
    }
    asm("" : "+r"(object)); // why: retain original object across calls before fallback address
    if (result == 0) result = object + 11068;
    return result;
}

