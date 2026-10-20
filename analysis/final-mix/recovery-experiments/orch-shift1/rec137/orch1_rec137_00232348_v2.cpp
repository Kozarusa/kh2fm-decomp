#include "../common/types.h"
extern "C" u32 func_00105c30(void);
extern "C" s32 func_00242e48();
extern "C" u8* D_0033caf0;
extern "C" u8* D_0033caf4;
extern "C" u8 D_003712d0[];
u8* func_00232348() {
    u8* result;
    if (func_00105c30() == 8) {
        if (func_00242e48() != 0) result = D_003712d0;
        else result = D_0033caf0;
    } else result = D_0033caf4;
    return result;
}
