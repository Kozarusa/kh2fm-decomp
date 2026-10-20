#include "../common/types.h"
extern "C" s64 func_001db200();
extern "C" s64 func_001db250(s64);

s64 func_001db198(s64 object, s64 mode) {
    s64 result = 1;
    if (mode != 0) {
        result = 0;
        if (mode >= 0) {
            if (mode < 3) {
                s64 inner = 0;
                if (func_001db200() != 0) {
                    inner = func_001db250(object) != 0;
                }
                result = inner;
            }
        }
    }
    return result;
}
