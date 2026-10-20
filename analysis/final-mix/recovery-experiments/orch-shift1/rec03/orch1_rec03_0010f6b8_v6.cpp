#include "../common/types.h"

bool func_0010f6b8(u8* object, f32 scale) {
    s32* data = *(s32**)(object + 0x48c);
    return data != 0 && data[0] < (s32)((f32)data[1] * scale);
}
