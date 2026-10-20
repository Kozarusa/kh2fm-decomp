#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" s32 func_0016c008(s32, s32);

void func_00172c38(s32* object) {
    s32 result = 0;
    do {
        result = func_001b9bc8(result);
        if (result == 0) {
            break;
        }
    } while (func_0016c008(result, object[1]) != object[2]);
    *(s32*)(object[0] + 4) = result;
}