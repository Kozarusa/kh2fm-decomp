#include "../common/types.h"
extern "C" u8* D_00352130;

f32 func_001d3000(f32 value) {
    u8* base = D_00352130;
    f32 high = *(f32*)(base + 0xf8);
    if (high <= value) {
        return *(f32*)(base + 0xf0);
    }
    f32 low = *(f32*)(base + 0xfc);
    if (value <= low) {
        return *(f32*)(base + 0xf4);
    }
    f32 ratio = (value - low) / (high - low);
    return *(f32*)(base + 0xf4) + (*(f32*)(base + 0xf0) - *(f32*)(base + 0xf4)) * ratio;
}
