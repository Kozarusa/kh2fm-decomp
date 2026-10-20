#include "../common/types.h"
extern "C" u32 func_00167f18(...);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_00290740(...);
extern "C" u32 func_001039f8(void);
extern "C" u64 func_00242618(u64,s8);
extern "C" u32 func_00287da0(void);
extern "C" u32 D_0035f238;

s32 func_0027db58() {
    u32 object = func_00167f18(0);
    s32 result;
    if (func_00287db0()) {
        u32 flag = func_00290740(D_0035f238);
        result = 0;
        if (!flag) {
            func_001039f8();
            result = 1;
        }
    } else {
    if (*(u64*)(object + 8) & 12) {
        func_00242618(9,1);
        func_00287da0();
    }
    result = 0;
    }
    return result;
}
