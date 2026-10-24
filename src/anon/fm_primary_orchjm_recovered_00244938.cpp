#include "../common/types.h"
extern "C" bool func_001a6d08(u32);

s32 func_00244938(s32 value) {
    s32 result = 1;
    if (value == 0) {
        if (func_001a6d08(1)) {
            result = func_001a6d08(118);
        }
    } else {
        result = func_001a6d08(1);
    }
    return result;
}
