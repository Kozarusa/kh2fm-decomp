#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001d87b8(s32);

u32 func_001cf998(void) {
    u32 result = 0;
    if (!func_001bb4a0() || (s32)func_001d87b8(1) > 0) {
        result = 1;
    }
    return result;
}