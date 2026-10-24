#include "../common/types.h"
extern "C" u32 D_003638d0;
extern "C" u64 func_00312db8(u64, u64);
extern "C" s32 func_001b0148(u32 arg1,u32 arg2,s32 arg3,u32 arg4);

s32 func_001affe0(u8* table, u32 first, u32 second) {
    s32 list[5];
    D_003638d0 *= 0x10dcd;
    s32 count = 0;
    s32 index = 0;
    s32 roll = (s32)func_00312db8((u64)D_003638d0, 0x28f5c29);
    s32* cursor = list;
    u8* entry = table;
    do {
        s32 result = func_001b0148((u32)table, first, (s8)entry[4], second);
        if (result >= 0) {
            s8 weight = (s8)entry[5];
            if (weight > 0) {
                roll -= weight;
                if (roll < 0) {
                    return result;
                }
            } else {
                *cursor = result;
                count++;
                cursor++;
            }
        }
        index++;
        entry += 2;
    } while (index < 5);
    if (count > 0) {
        u32 seed = D_003638d0 * 0x10dcd;
        D_003638d0 = seed;
        u64 high = func_00312db8((u64)(u32)(count - 1) + 0x100000000ULL, (u64)(u32)count);
        return list[(s32)func_00312db8((u64)seed, high)];
    }
    return -1;
}
