#include "../common/types.h"
extern "C" s64 func_00293200(void);
extern "C" s64 func_00292f18(void);
extern "C" s64 func_00292fe8(void);
extern "C" s16 D_0035f4e0;
extern "C" s32 D_0035f4c4;

s64 func_00292eb0(void) {
    s64 result = -1;
    if (func_00293200() == 0) {
        result = 0;
        if (D_0035f4e0 != 0) {
            if (D_0035f4c4 == 0) result = func_00292f18();
            else result = func_00292fe8();
        }
    }
    return result;
}
