#include "../common/types.h"
extern "C" s32 D_00352134;
extern "C" u8* func_00168b88(s32, s32, s32, s32);

s32 func_001ce248(s32 handle, s8* bytes) {
    s32 b1 = bytes[1];
    s32 b3 = bytes[3];
    s32 b2 = bytes[2];
    s32 b0 = bytes[0];
    s32 packed = b0 | (b3 << 24) | ((b2 << 16) | (b1 << 8));
    u8* result = func_00168b88(D_00352134, handle, packed, 0);
    return *(s32*)(result + 8);
}