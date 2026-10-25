#include "../common/types.h"
extern "C" u32 D_003638d0;
extern "C" u8 D_01d5baa0[];
extern "C" u64 func_00312db8(u64, u64);
// why: no accepted declaration; the original passes its entry a0 through unchanged and uses the v0 result as an index
extern "C" s32 func_001d9af8(u8*);
// why: no accepted declaration; the original sets only a0 from the func_001d9af8 result
extern "C" void func_001d9ad8(s32);
extern "C" u32 func_001d9c68(u8* data);

s32 func_001d9b40(u8* key) {
    s32 slot = func_001d9af8(key);
    u8* entry = D_01d5baa0 + slot;
    u8 previous = *entry;
    s8 free_slots[16];
    s32 count = 0;
    *entry = 1;
    s32 result = (previous == 2);
    for (s32 index = 0; index < 5; index++) {
        if (D_01d5baa0[index] == 0) {
            free_slots[count] = index;
            count++;
        }
    }
    if (count > 0) {
        u32 seed = D_003638d0 * 0x10dcd;
        D_003638d0 = seed;
        u64 step = func_00312db8((u64)(u32)(count - 1) + 0x100000000ULL, (u64)(u32)count);
        s32 pick = (s32)func_00312db8((u64)seed, step);
        D_01d5baa0[free_slots[pick]] = 2;
    }
    if (func_001d9c68(D_01d5baa0) != 0) {
        func_001d9ad8(slot);
    }
    return result;
}
