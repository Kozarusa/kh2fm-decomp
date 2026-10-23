#include "../common/types.h"

s32 func_0016ffc8(u8* object) {
    s32 original = *(s32*)(object + 0x28);
    if (original < 0 && object[0] == 0) {
        s32 candidate = *(s32*)(object + 0x38);
        if ((u32)(candidate - 2300) < 100 || (u32)(candidate - 2410) < 10 || (u32)(candidate - 2420) < 10) {
            return candidate;
        }
    }
    return original;
}
