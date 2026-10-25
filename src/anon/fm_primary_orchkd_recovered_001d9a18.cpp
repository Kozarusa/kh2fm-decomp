#include "../common/types.h"
extern "C" u32 D_003638d0;
extern "C" u64 func_00312db8(u64, u64);

// Preserve original registry aliases.
void func_001d9a18(u8* slots, s32 skip) asm("_Z16wtarget_001d9a18jjjj");

void func_001d9a18(u8* slots, s32 skip) {
    for (s32 i = 0; i < 5; i++) {
        slots[i] = 0;
    }
    s32 index;
    if (skip < 0) {
        u32 seed = D_003638d0 * 0x10dcd;
        D_003638d0 = seed;
        index = (s32)func_00312db8((u64)seed, 0x33333334);
    } else {
        u32 seed = D_003638d0 * 0x10dcd;
        D_003638d0 = seed;
        index = (s32)(((u64)seed << 2) >> 32);
        if (index >= skip) {
            index++;
        }
    }
    slots[index] = 2;
}
