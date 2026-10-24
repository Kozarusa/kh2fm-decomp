#include "../common/types.h"
extern "C" u32 func_00105c30(void);

u32 func_002efbb8(void) {
    s32 region = func_00105c30();
    u32 result;
    switch (region) {
    case 2:
        result = 0x5355;
        break;
    case 1:
    case 8:
        result = 0x504a;
        break;
    default:
        result = 0x5545;
        break;
    }
    return result;
}
