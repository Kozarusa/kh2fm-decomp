#include "../common/types.h"

s32 func_00207308(s32* object, u8* other) {
    if (object[4] == 0) {
        return 0;
    }
    if (other[0x106] != 0) {
        if (object[5] == 0) {
            return 0;
        }
    }
    if (other[0x101] == 0) {
        return 1;
    }
    if (object[6] == 0) {
        return 0;
    }
    return 1;
}