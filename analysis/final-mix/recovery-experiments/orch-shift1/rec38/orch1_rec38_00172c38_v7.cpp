#include "../common/types.h"
extern "C" s64 func_001b9bc8(s64);
extern "C" s32 func_0016c008(s64, s32);

void func_00172c38(s32* object) {
    s64 result = 0;
    while (1) {
        result = func_001b9bc8(result);
        if (result == 0) {
            *(s32*)(object[0] + 4) = (s32)result;
            return;
        }
        if (func_0016c008(result, object[1]) == object[2]) {
            *(s32*)(object[0] + 4) = (s32)result;
            return;
        }
    }
}