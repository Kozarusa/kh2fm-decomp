#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" bool func_00198d00(s32, s32);
extern "C" u8* D_01d49320;

s32 func_001bb7f8(void) {
    // why: original keeps the result live across both calls in s0
    register s32 result asm("$16") = 0;
    if (func_001bb4a0()) {
        if (func_00198d00(8, -1) == 0) {
            if (*(s32*)(D_01d49320 + 0xac) == 0) {
                return result;
            }
        }
        result = 1;
    }
    return result;
}
