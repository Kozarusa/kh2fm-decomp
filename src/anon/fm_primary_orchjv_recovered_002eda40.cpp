#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" s32 func_001991a8(s32, s32);

// why: void under the 2026-10-20 second mixed-exit ruling: the two jr ra exits leave the
// caller's entry v0 untouched (no parameter to return), the j exit leaves func_001991a8's v0.

// Preserve original registry aliases.
void func_002eda40(f32* timer) asm("_Z16wtarget_002eda40jjjj");

void func_002eda40(f32* timer) {
    f32 value = *timer;
    if (0.0f < value) {
        f32 remaining = value - D_00349e10;
        *timer = remaining;
        if (remaining <= 0.0f) {
            func_001991a8(0x97, 0);
        }
    }
}
