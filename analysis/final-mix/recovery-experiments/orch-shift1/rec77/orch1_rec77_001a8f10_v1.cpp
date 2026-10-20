#include "../common/types.h"

s32 func_001a8f10(s32 value) {
    s32 result = 1;
    if (value != 2) {
        if (value < 3) {
            if (value == 1) {
                return 0;
            }
            result = 3;
        } else {
            result = 2;
            if (value != 3) {
                if (value == 14) {
                    return 0;
                }
                result = 3;
            }
        }
    }
    return result;
}
