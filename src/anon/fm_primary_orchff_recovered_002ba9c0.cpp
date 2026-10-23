#include "../common/types.h"
extern "C" s32 D_003616e0;
extern "C" s32 D_01e2a400[];
extern "C" u64 func_002b6c04(u32);

// Preserve original registry aliases.
u64 func_002ba9c0() asm("_ZN2Tz9MenuSound15ResetVoiceStateEv");

u64 func_002ba9c0() {
    u32 value = 0;
    s32 count = D_003616e0;
    if (count != 0) {
        s32 next = count - 1;
        D_003616e0 = next;
        if (next > 0) {
            s32 slot = count - 2;
            value = D_01e2a400[slot];
        }
    }
    return func_002b6c04(value);
}
