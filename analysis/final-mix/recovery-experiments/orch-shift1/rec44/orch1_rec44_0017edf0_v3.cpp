#include "../common/types.h"
extern "C" s32 func_001a97b8(...);

s32 func_0017edf0(s32* object, s32 index) {
    s32 result = 0;
    if (index >= 0 && *object != 0) {
        if (object[1] != 0) {
            result = func_001a97b8(object[1]);
            if (result != 0) {
                return result;
            }
        }
        return func_001a97b8(*object, index);
    }
    return result;
}
