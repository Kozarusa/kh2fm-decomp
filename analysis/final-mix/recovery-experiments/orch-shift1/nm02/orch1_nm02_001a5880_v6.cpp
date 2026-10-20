#include "../common/types.h"
extern "C" u32 D_00350790;
extern "C" u8 D_0036d4e8[];
extern "C" void func_001a5420(u32, u8*, u32);

void func_001a5880(u32 value, s32 index, s32 count) {
    if (count > 0) {
        s32 offset = index * 16;
        do {
            count = count - 1;
            func_001a5420(D_00350790, D_0036d4e8 + offset, value);
        } while (count != 0);
    }
}
