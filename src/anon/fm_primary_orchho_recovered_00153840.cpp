#include "../common/types.h"
extern "C" s32 D_0034a77c;
extern "C" u8* D_0034a790;
extern "C" void func_00153948(u8);

void func_00153840(u64 mask) {
    s32 count = D_0034a77c;
    s32 slot;
    s32 index;
    for (slot = 0; slot < count; slot++) {
        D_0034a790[slot * 64 + 48] = 1;
    }
    for (index = 0; index < 64; index++) {
        u64 bit = (u64)1 << index;
        if (mask & bit) {
            func_00153948(index);
        }
    }
}
