#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028acb8(u32);
extern "C" u32 func_0028aa40(u32);
extern "C" u32 D_0035f01c;
u32 func_00271e08() {
    u32 object = func_00257770();
    u32 result = func_00287bc0();
    if (result == 25) {
        func_0028dac8(object,142);
        result = func_0028acc8(D_0035f01c);
        if (result) {
            result = func_0028acb8(D_0035f01c);
            if (!result) return func_0028aa40(D_0035f01c);
        }
    }
    return result;
}
