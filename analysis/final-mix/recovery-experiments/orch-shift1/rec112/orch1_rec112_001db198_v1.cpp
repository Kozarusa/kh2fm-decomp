#include "../common/types.h"
extern "C" s64 func_001db200();
extern "C" s64 func_001db250(s64);

bool func_001db198(s64 object, s64 mode) {
    bool result = true;
    if (mode != 0) {
        if (mode < 0) {
            result = false;
        } else {
            result = false;
            if (mode < 3) {
                result = false;
                if (func_001db200() != 0) {
                    result = func_001db250(object) != 0;
                }
            }
        }
    }
    return result;
}
