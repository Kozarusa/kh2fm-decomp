#include "../common/types.h"

s32 func_00186ce8(u8* object) {
    s32 result = 0;
    if (*(s32*)(object + 0x140) != 0) {
        s32 value = *(s32*)(object + 0x154);
        if (value > 9) {
            result = value < 40;
        }
    }
    return result;
}
