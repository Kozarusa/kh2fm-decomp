#include "../common/types.h"

extern "C" u32 func_001991a8(...);

u32 func_002eda90(f32 threshold, f32* object) {
    u32 result = func_001991a8(140);
    f32 value = *object;

         f32 limit = 1.0f;
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
