#include "../common/types.h"

s32 func_0010f6b8(u8* object, f32 scale) {
    s32* data = *(s32**)(object + 0x48c);
    s32 result;
    if (data == 0) {
        result = 0;
    } else {
        s32 limit = (s32)((f32)data[1] * scale);
        s32 less = data[0] < limit;
        if (less != 0) {
            result = 1;
        } else {
            result = 0;
        }
    }
    return result;
}
