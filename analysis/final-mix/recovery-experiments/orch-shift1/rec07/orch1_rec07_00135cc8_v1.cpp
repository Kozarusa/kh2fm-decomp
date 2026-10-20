#include "../common/types.h"

void func_00135cc8(s32* object, s32 oldValue, s32 newValue) {
    s32 count = object[3];
    s32 index;
    for (index = 0; index < count; index++) {
        if (object[4] == oldValue) {
            object[4] = newValue;
            return;
        }
        object++;
    }
}
