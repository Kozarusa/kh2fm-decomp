#include "../common/types.h"
extern "C" s64 func_001c8ab0(void);
extern "C" s64 func_001dcd38(void);

u32 func_001dcc60(s32* object) {
    u32 result = 0;
    if (func_001dcd38() != 1) {
        if (func_001c8ab0() == 1) {
            return result;
        }
    }
    result = (object[2] & 0x800000) == 0;
    return result;
}