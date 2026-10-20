#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" bool func_00198d00(s32, s32);
extern "C" u8* D_01d49320;

s32 func_001bb7f8(void) {
    s32 result = 0;
    if (func_001bb4a0()) {
        if (func_00198d00(8, -1)) {
            result = 1;
        } else if (*(s32*)(D_01d49320 + 0xac) != 0) {
            result = 1;
        }
    }
    return result;
}
