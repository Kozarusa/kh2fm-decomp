#include "../common/types.h"

s32 func_00135c88(s32* object, s32 value) {
    s32 count = object[3];
    s32 index;
    for (index = 0; index < count; index++) {
        if (object[index + 4] == value) {
            return index;
        }
    }
    return -1;
}
