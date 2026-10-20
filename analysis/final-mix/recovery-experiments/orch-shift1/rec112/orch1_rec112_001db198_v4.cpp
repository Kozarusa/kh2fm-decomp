#include "../common/types.h"
extern "C" s64 func_001db200();
extern "C" s64 func_001db250(s64);

s64 func_001db198(s64 object, s64 mode) {
    if (mode != 0) {
        if (mode < 0) {
            return 0;
        }
        if (mode < 3) {
            s64 result = 0;
            if (func_001db200() != 0) {
                result = func_001db250(object) != 0;
            }
            return result;
        }
        return 0;
    }
    return 1;
}
