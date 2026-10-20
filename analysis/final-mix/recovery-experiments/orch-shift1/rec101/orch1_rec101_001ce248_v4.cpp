#include "../common/types.h"
extern "C" s32 D_00352134;
extern "C" u8* func_00168b88(s32, s32, s32, s32);

s32 func_001ce248(s32 handle, s8* bytes) {
    s32 packed = ((bytes[1] << 8) | (bytes[2] << 16)) | (bytes[3] << 24) | bytes[0];
    u8* result = func_00168b88(D_00352134, handle, packed, 0);
    return *(s32*)(result + 8);
}