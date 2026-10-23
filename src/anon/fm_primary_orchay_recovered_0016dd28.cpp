#include "../common/types.h"
extern "C" s32 D_0034d8a8;
extern "C" u64 func_00312db8(u64, u64);

void func_0016dd28(s32* pointer) {
    s32 seed = D_0034d8a8 * 0x10dcd;
    u32 limit = *(u32*)pointer;
    D_0034d8a8 = seed;
    u64 high = func_00312db8((u64)(limit - 1) + 0x100000000ULL, limit);
    *pointer = (s32)func_00312db8((u64)(u32)seed, high);
}
