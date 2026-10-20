#include "../common/types.h"
extern "C" bool func_0013ba50(...);

s32 func_0013b9e0(u8* object, s32 mode) {
    s32 result = 0;
    if (func_0013ba50(object)) {
        return 0;
    }
    if (mode == 0) {
        result = 1;
        if (*(s32*)(object + 0xec) == 6) {
            return result;
        }
    }
    result = 0;
    if (mode == 6) {
        result = 1;
        if (*(s32*)(object + 0xec) == 0) {
            return result;
        }
        result = 0;
    }
    return result;
}