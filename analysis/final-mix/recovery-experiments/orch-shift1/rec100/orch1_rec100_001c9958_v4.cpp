#include "../common/types.h"

bool func_001c9958(s32 kind, s32 value) {
    bool result = false;
    bool inRange = kind < 7 && kind != 0;
    if (inRange) {
        result = value == 2;
        if (kind != 2) {
            s32 other;
            if (2 < kind) {
                other = 3;
            } else {
                other = 1;
            }
            result = 2 >= kind && value == 3;
            if (kind != other) {
                result = true;
            }
        }
    }
    return result;
}