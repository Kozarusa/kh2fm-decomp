#include "../common/types.h"

s32 func_00186ce8(u8* object) {
    s32 result = 0;
    s32* inner = (s32*)(object + 0x140);
    if (inner[0] != 0) {
        s32 value = inner[5];
        if (value > 9) {
            result = value < 40;
        }
    }
    return result;
}