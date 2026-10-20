#include "../common/types.h"
extern "C" f32 D_0036c544;
extern "C" f32 D_0036c548;
extern "C" f32 func_002f8b00(f32, f32);

f32 func_0017ce10(f32 value) {
    f32 offset = D_0036c544;
    if (0.0f < value) {
        f32 result = func_002f8b00(value + offset, D_0036c548);
        return result - offset;
    } else {
        f32 result = func_002f8b00(offset - value, D_0036c548);
        return offset - result;
    }
}
