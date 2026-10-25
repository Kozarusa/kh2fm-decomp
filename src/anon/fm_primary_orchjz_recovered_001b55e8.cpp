#include "../common/types.h"
extern "C" u32 func_0016f7d0(u64,s64);
extern "C" bool func_001d1ca8(s32);
extern "C" bool func_001d1f08(s32);
extern "C" u32 func_001c9df8(void);

bool func_001b55e8(s32* object) {
    s32 inner = *(s32*)(object[0] + 36);
    if (inner != 0 && (func_0016f7d0(inner, 0) & 8) != 0) {
        return false;
    }
    if (func_001d1ca8((s32)(object + 26))) {
        return false;
    }
    if (func_001d1f08((s32)(object + 42))) {
        return false;
    }
    if (func_001c9df8() != 0) {
        return false;
    }
    bool flag = false;
    if (object[9] == 0) {
        flag = object[15] == 0;
    }
    return flag;
}
