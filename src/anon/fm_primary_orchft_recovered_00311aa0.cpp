#include "../common/types.h"

// Preserve original registry aliases.
u64 func_00311aa0(u64 left, u64 right) asm("_Z13func_00311aa0xx");

u64 func_00311aa0(u64 left, u64 right) {
    u32 leftLow = (u32)left;
    u32 leftHigh = (u32)(left >> 32);
    u32 rightLow = (u32)right;
    u32 rightHigh = (u32)(right >> 32);
    u64 product = (u64)leftLow * rightLow;
    u32 cross = leftLow * rightHigh + leftHigh * rightLow;
    u32 high = (u32)(product >> 32) + cross;
    return (product & 0xffffffff) | ((u64)high << 32);
}
