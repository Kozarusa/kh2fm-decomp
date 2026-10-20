#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" s32 func_0016a070(s32);

s32 func_0016b800(s32 part) {
    s32 object = 0;
    while ((object = func_001b9bc8(object)) != 0) {
        if (func_0016a070(object) == part) {
            return object;
        }
    }
    return object;
}
