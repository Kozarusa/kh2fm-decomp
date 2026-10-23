#include "../common/types.h"
extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);
extern "C" s32 D_0035f038;

// Preserve original registry aliases.
u32 func_00257be0(void) asm("_Z13func_00257be0Pv");

u32 func_00257be0(void) {
    u32 result;
    result = func_00139d78(D_0035f038 + 0xb350);
    if (result != 0) {
        func_00139510(D_0035f038 + 0xb350);
    }
    result = func_00139d78(D_0035f038 + 0xb504);
    if (result != 0) {
        func_00139510(D_0035f038 + 0xb504);
    }
    result = func_00139d78(D_0035f038 + 0xb6b8);
    if (result == 0) {
        return result;
    }
    return func_00139510(D_0035f038 + 0xb6b8);
}
