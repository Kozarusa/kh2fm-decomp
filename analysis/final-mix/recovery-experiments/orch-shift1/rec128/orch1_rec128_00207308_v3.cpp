#include "../common/types.h"

s32 func_00207308(s32* object, u8* other) {
    s32 result = 0;
    if (object[4] != 0) {
        u8 flag;
        if (other[0x106] == 0) {
            flag = other[0x101];
        } else {
            if (object[5] == 0) {
                return 0;
            }
            flag = other[0x101];
        }
        result = 1;
        if (flag != 0) {
            result = 0;
            if (object[6] != 0) {
                result = 1;
            }
        }
    }
    return result;
}