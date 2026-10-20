#include "../common/types.h"
extern "C" f32 D_003713ac;
union Color { u32 word; u8 bytes[4]; };
u32 func_002338a8(u32 value, f32 scale) {
    Color result;
    result.word = value;
    if (scale != D_003713ac) {
        u32 alpha = value >> 24;
        f32 scaled = (f32)alpha * scale;
        register f32 rounded asm("$f1"); // why: original conversion destination uses f1
        asm("cvt.w.s %0,%1" : "=f"(rounded) : "f"(scaled)); // why: matches original conversion, accepted 0016df28 primitive
        union { f32 value; u32 word; } converted;
        converted.value = rounded;
        u32 amount = converted.word;
        if (amount < 256) result.bytes[3] = amount;
        else result.bytes[3] = 255;
    }
    return result.word;
}
