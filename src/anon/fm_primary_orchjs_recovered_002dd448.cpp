#include "../common/types.h"
extern "C" u32 func_001d86a0(...);
extern "C" u32 D_00375dc8[];

void func_002dd448(u8* object, s32 multiplier, s32 index) {
    u32 counts[3] = {D_00375dc8[0], D_00375dc8[1], D_00375dc8[2]};
    if (*(s32*)(object + 0x80) == 2) {
        func_001d86a0(counts[index] * multiplier, 0);
    }
}
