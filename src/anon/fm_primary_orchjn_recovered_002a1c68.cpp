#include "../common/types.h"
extern "C" u8 D_0035f5e0;
extern "C" u8 D_0035f5e1;
extern "C" u32 D_0035f5dc;
extern "C" u32 func_0023f900(u32);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00293d80(s32);
extern "C" s64 func_00292630();

s64 func_002a1c68() {
    s64 result = func_00292630();
    if (result != 0) return result;
    if (D_0035f5e0 != 0 && func_0023f900(D_0035f5dc) != 0) {
        func_0023fad0(D_0035f5dc);
    }
    u32 word = func_00293d80(5101);
    asm("" : "=r"(result) : "0"(word)); // why: callee v0 word flows out unchanged in the 64-bit result register
    D_0035f5e0 = 0;
    D_0035f5e1 = 0;
    return result;
}
