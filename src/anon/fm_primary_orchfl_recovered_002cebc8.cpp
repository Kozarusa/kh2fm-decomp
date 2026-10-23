#include "../common/types.h"
extern "C" u32* D_00361f60;

s32 func_002cebc8(s32 argument) {
    s32 result;
    u32* object = D_00361f60;
    if (object != 0) {
        result = ((s32 (*)(u32*, s32))(*(u32**)object)[4])(object, argument);
    } else {
        result = 0;
    }
    return result;
}
