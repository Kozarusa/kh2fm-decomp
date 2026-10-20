#include "../common/types.h"
extern "C" u32 func_001d2180(...);
extern "C" f32 D_00349e10;

u32 func_001d21c0(u8* object) {
    f32 value = *(f32*)(object + 0x3c);
    if (value > 0.0f) {
        value = value - D_00349e10;
        *(f32*)(object + 0x3c) = value;
        if (value <= 0.0f) {
            func_001d2180();
            return 0;
        }
    }
    return 1;
}