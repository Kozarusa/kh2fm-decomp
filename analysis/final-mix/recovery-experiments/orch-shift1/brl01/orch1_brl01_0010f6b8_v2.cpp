#include "../common/types.h"

s32 func_0010f6b8(u8* object, f32 scale) {
    s32* data = *(s32**)(object + 0x48c);
    s32 result = 0;
    if (data != 0) {
        result = 1;
        // why: keeps the constant 1 opaque so the compare stays a branch
        asm("" : "+r"(result));
        if (!(data[0] < (s32)((f32)data[1] * scale))) {
            result = 0;
        }
    }
    return result;
}
