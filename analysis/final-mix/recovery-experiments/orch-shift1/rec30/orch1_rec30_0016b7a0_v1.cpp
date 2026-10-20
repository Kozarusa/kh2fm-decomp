#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" s32 func_0016bff0(s32);

s32 func_0016b7a0(s32 serial) {
    s32 object = 0;
    while (1) {
        object = func_001b9bc8(object);
        if (object == 0) {
            return object;
        }
        if (func_0016bff0(object) == serial) {
            return object;
        }
    }
}