#include "../common/types.h"
extern "C" u32 func_001a3188(...);

void func_00188958(u8* object, s32 count) {
    s32 index;
    if (object[0x12] < count) {
        for (index = object[0x12]; index < count; index++) {
            ((u16*)(object + 0x34))[index] = 0;
            ((u16*)(object + 0x44))[index] = 0;
        }
    } else {
        for (index = count; index < object[0x12]; index++) {
            u16* slot = (u16*)(object + 0x34) + index;
            if (*slot != 0) {
                func_001a3188(*slot, 100, 0);
                *slot = 0;
            }
        }
    }
    object[0x12] = count;
}
