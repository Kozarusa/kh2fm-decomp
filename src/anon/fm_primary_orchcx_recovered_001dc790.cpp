#include "../common/types.h"

extern "C" u32 func_001dc738(...);

s32 func_001dc790(s32* object) {
    s32 result = 0;
    if (func_001dc738(object) != 0 || (object[2] & 0x200000) != 0) result = 1;
    return result;
}
