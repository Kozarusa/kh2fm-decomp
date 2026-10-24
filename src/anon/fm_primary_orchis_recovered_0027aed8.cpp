#include "../common/types.h"
extern "C" s32 func_0027ae20(void);

void func_0027aed8(s32 value, u32* flag, s32* output) {
    if (value == 0) {
        *flag = 0;
        *output = 0;
    } else {
        s32 count = func_0027ae20();
        s32 result = value - count;
        if (count != 0 && value < count + 1) {
            result = value - 1;
            *flag = 1;
        } else {
            *flag = 0;
        }
        *output = result;
    }
}
