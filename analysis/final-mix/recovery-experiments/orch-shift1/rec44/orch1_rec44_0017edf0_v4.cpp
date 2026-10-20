#include "../common/types.h"
extern "C" s32 func_001a97b8(...);

s32 func_0017edf0(s32* object, s32 index) {
    s32 value;
    if (index < 0 || *object == 0) {
        value = 0;
    } else {
        value = object[1];
        if (value == 0 || (value = func_001a97b8(value)) == 0) {
            return func_001a97b8(*object, index);
        }
    }
    return value;
}
