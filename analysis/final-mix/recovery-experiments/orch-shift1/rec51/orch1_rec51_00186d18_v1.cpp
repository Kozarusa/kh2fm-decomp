#include "../common/types.h"

s32 func_00186d18(u8* object) {
    s32 result = 0;
    if (*(s32*)(object + 320) != 0) {
        s32 value = *(s32*)(object + 340);
        if (value >= 140) {
            result = value < 151;
        }
    }
    return result;
}
