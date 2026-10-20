#include "../common/types.h"
extern "C" s32 D_003528f8;
extern "C" s32 func_001d7f10();

s32 func_001d7ec8(s32 index) {
    s32 flag = func_001d7f10();
    s32 result = 0;
    if (flag != 0) {
        s32 base = D_003528f8;
        result = base + *(s32*)(base + index * 4 + 8);
    }
    return result;
}
