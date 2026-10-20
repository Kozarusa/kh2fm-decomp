#include "../common/types.h"

s32 func_00154ee8(u8* object) {
    s32 value = *(s32*)(object + 0x18);
    s32 result = 0x43;
    if (value != 1) {
        if (value < 2) {
            if (value == 0) {
                return 0x48;
            }
            result = 0x48;
        } else {
            if (value == 2) {
                return 0x48;
            }
            result = 0x48;
        }
    }
    return result;
}