#include "../common/types.h"

s32 func_00154288(s32 unused, s32 value) {
    s32 result = 0;
    if (value != 1) {
        if (value < 2) {
            result = 3;
            if (value != 0) {
                result = 3;
            }
        } else {
            result = 2;
            if (value != 2) {
                return 3;
            }
        }
    }
    return result;
}