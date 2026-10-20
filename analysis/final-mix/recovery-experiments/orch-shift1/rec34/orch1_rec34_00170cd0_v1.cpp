#include "../common/types.h"
extern "C" s32 func_001688b8();
extern "C" s32 func_002ba200();
extern "C" s32 func_00170c50();

s32 func_00170cd0() {
    if (func_001688b8() == 0 && func_002ba200() == 0) {
        return func_00170c50();
    }
    return 1;
}