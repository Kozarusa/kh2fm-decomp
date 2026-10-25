#include "../common/types.h"
extern "C" u32 func_00168b38(void*,u32,s32);
extern "C" u32 func_001a97b8(...);
extern "C" u32 func_001a9780(u32); // no accepted caller: one word argument in a0

u32 func_001a9458(u8* object, s32 group, s32 slot) {
    u32 entry = 0;
    u32 result;
    if (func_001a9780(*(u32*)(object + 0x14)) != 0) {
        group = group * 4;
        if (slot >= 0) {
            entry = func_001a97b8(*(u32*)(object + 0x14), group + slot);
        }
        if (entry == 0) {
            s32 index = 3;
            do {
                entry = func_001a97b8(*(u32*)(object + 0x14), group + index);
                index--;
                if (entry != 0) {
                    // why: the scan hit skips the entry test and enters the lookup block directly, as the original bnez to 001a94dc does
                    goto found;
                }
            } while (index >= 0);
        }
    } else {
        entry = func_001a97b8(*(u32*)(object + 0x14), group);
    }
    // why: one shared return 0 after this block keeps the result in v0 (separate early returns allocate t7)
    if (entry != 0) {
found:
        result = func_00168b38((void*)entry, 9, 0);
        if (result != 0) {
            return *(u32*)(result + 8);
        }
    }
    return 0;
}
