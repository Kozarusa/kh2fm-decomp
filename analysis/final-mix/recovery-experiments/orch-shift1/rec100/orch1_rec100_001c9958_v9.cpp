#include "../common/types.h"

bool func_001c9958(s32 kind, s32 value) {
    bool result = false;
    bool inRange = kind != 0 && kind < 7;
    if (inRange) {
        result = value == 2;
        if (kind != 2) {
            s32 other;
            if (kind > 2) {
                other = 3;
                result = false;
            } else {
                other = 1;
                result = value == 3;
            }
            if (kind != other) {
                result = true;
            }
        }
    }
    return result;
}