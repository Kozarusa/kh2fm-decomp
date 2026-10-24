#include "../common/types.h"

extern "C" f32 D_003761a4;
extern "C" u32 func_001991a8(...);

u32 func_002eda90(f32 threshold, f32* object) {
    u32 result = func_001991a8(140);
    f32 value = *object;
    f32* limitPointer = &D_003761a4;
    asm("" : "+r"(limitPointer)); // why: keeps the full address materialized before the zero-offset load
    f32 limit = *limitPointer;
    if (!(value < threshold)) {
        // value is already at least threshold, or unordered
    } else {
        value = threshold;
        *object = value;
    }

    if (!(limit < value)) value = limit;
    *object = value;
    return result;
}
