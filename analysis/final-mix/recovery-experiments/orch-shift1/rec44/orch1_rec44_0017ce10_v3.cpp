#include "../common/types.h"
extern "C" volatile f32 D_0036c544;
extern "C" volatile f32 D_0036c548;
extern "C" f32 func_002f8b00(f32, f32);

f32 func_0017ce10(f32 value) {
    f32 offset;
    if (0.0f < value) {
        offset = D_0036c544;
        f32 result = func_002f8b00(value + offset, D_0036c548);
        return result - offset;
    } else {
        offset = D_0036c544;
        f32 result = func_002f8b00(offset - value, D_0036c548);
        return offset - result;
    }
}
