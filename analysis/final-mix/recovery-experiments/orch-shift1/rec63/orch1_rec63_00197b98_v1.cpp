#include "../common/types.h"

extern "C" s32 D_0035037c;
extern "C" f32 D_0036d0a8;
extern "C" s32 func_002283f8();

f32 func_00197b98() {
    f32 result = 0.0f;
    if (D_0035037c != 0) {
        result = D_0036d0a8;
        if (*(s32*)(D_0035037c + 0x30) == 8) {
            result = (f32)func_002283f8();
        }
    }
    return result;
}
