#include "../common/types.h"
extern "C" u8* D_00352130;

f32 func_001d3000(f32 value) {
    if (*(f32*)(D_00352130 + 0xf8) <= value) {
        return *(f32*)(D_00352130 + 0xf0);
    }
    f32 low = *(f32*)(D_00352130 + 0xfc);
    if (value <= low) {
        return *(f32*)(D_00352130 + 0xf4);
    }
    return *(f32*)(D_00352130 + 0xf4) +
           (*(f32*)(D_00352130 + 0xf0) - *(f32*)(D_00352130 + 0xf4)) *
           ((value - low) / (*(f32*)(D_00352130 + 0xf8) - low));
}
