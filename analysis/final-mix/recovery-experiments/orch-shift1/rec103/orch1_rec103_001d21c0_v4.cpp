#include "../common/types.h"
extern "C" u32 func_001d2180(...);
extern "C" f32 D_00349e10;

u32 func_001d21c0(u8* object) {
    f32 value = *(volatile f32*)(object + 0x3c);
    if (value > 0.0f) {
        f32 next = value - D_00349e10;
        *(f32*)(object + 0x3c) = next;
        if (next <= 0.0f) {
            func_001d2180();
            return 0;
        }
    }
    return 1;
}