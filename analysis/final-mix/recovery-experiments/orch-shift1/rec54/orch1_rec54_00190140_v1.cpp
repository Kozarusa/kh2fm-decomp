#include "../common/types.h"
extern "C" s32 func_00190208(s32* object, s32 flag);

s32 func_00190140(s32* object) {
    s32 result = 0;
    if (object[2] != 0 || func_00190208(object, 0) != 0) {
        result = 1;
    }
    return result;
}
