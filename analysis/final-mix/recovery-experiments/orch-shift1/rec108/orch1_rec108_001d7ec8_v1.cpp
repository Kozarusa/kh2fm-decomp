#include "../common/types.h"
extern "C" s32 D_003528f8;
extern "C" s32 func_001d7f10();

s32 func_001d7ec8(s32 index) {
    s32 result = 0;
    if (func_001d7f10() != 0) {
        result = D_003528f8;
        result += *(s32*)(result + index * 4 + 8);
    }
    return result;
}