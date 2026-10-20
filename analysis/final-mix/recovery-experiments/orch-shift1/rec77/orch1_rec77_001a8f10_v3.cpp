#include "../common/types.h"

s32 func_001a8f10(s32 value) {
    if (value == 2) {
        return 1;
    }
    if (value < 3) {
        if (value == 1) {
            return 0;
        }
        return 3;
    }
    if (value == 3) {
        return 2;
    }
    if (value != 14) {
        return 3;
    }
    return 0;
}
