#include "../common/types.h"
extern "C" u8 D_0032e020[];
extern "C" s32 func_00188fe0(...);
extern "C" void func_001a34e0(u32, s32);

// Preserve original registry aliases.
s32 func_001a3458(u32 item, s32 count) asm("_ZN2YS4ITEM6ReduceEii");

s32 func_001a3458(u32 item, s32 count) {
    if (count == 100) {
        func_001a34e0(item, 1);
        return 1;
    }
    u8* record = (u8*)func_00188fe0(D_0032e020, count);
    for (s32 index = record[18] - 1; index >= 0; index--) {
        u16* slot = (u16*)(record + 52) + index;
        if (*slot == item) {
            *slot = 0;
            return 1;
        }
    }
    return 0;
}
