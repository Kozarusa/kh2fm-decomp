#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u8* func_001bbcb0(void);

s32 func_001bc0e0(void) {
    s32 result = 0;
    if (func_001bb4a0()) {
        if ((*(u32*)(func_001bbcb0() + 4) & 0x10) == 0) {
            result = 1;
        }
    } else {
        result = 1;
    }
    return result;
}
