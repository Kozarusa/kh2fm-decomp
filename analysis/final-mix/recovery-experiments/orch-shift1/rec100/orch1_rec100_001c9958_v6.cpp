#include "../common/types.h"

bool func_001c9958(s32 kind, s32 value) {
    bool result = false;
    bool inRange = kind < 7 && (kind ^ 0) != 0;
    if (inRange) {
        result = value == 2;
        if (kind != 2) {
            if (kind < 3) {
                result = value == 3;
                if (kind != 1) {
                    result = true;
                }
            } else {
                result = false;
                if (kind != 3) {
                    result = true;
                }
            }
        }
    }
    return result;
}