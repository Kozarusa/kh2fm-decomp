#include "../common/types.h"
extern "C" u32 D_003638d0;
extern "C" u64 func_00312db8(u64, u64);
// why: declaration copied from accepted caller fm_primary_orchjz_recovered_001bf010.cpp (types of the accepted definition u32 func_001c8bb8(u8*) in auto80_199_queue.cpp; the varargs u64 placeholder adds a truncation)
extern "C" u32 func_001c8bb8(u8*);

s8 func_001c8c38() {
    s8 list[16];
    u32 count = func_001c8bb8((u8*)list);
    u32 seed = D_003638d0 * 0x10dcd;
    D_003638d0 = seed;
    u64 high = func_00312db8((u64)(u32)(count - 1) + 0x100000000ULL, (u64)count);
    return list[(s32)func_00312db8((u64)seed, high)];
}
