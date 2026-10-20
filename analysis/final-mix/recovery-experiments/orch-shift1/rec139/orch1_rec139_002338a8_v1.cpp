#include "../common/types.h"
extern "C" f32 D_003713ac;
union Color { u32 word; u8 bytes[4]; };
u32 func_002338a8(u32 value, f32 scale) {
    Color result;
    result.word = value;
    if (scale != D_003713ac) {
        u32 alpha = value >> 24;
        u32 amount = (u32)((f32)alpha * scale);
        if (amount < 256) result.bytes[3] = amount;
        else result.bytes[3] = 255;
    }
    return result.word;
}
