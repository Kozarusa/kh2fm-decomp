#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" u32 func_0016c008(s32, s32);

u32 func_00172c38(s32* object) {
    u32 value;
    register s32 result asm("$16") = 0; // why: original keeps the found object in s0 and the owner in s1
    while ((value = result = func_001b9bc8(result)) != 0) {
        value = func_0016c008(result, object[1]);
        if (value == (u32)object[2]) {
            break;
        }
    }
    *(s32*)(object[0] + 4) = result;
    return value;
}
