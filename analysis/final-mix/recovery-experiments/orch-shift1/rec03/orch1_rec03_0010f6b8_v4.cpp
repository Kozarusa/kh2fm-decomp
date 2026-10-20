#include "../common/types.h"

s32 func_0010f6b8(u8* object, f32 scale) {
    s32* data = *(s32**)(object + 0x48c);
    if (data != 0) {
        if (data[0] < (s32)((f32)data[1] * scale)) {
            return 1;
        }
        return 0;
    }
    return 0;
}
