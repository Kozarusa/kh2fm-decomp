#include "../common/types.h"
extern "C" s16* D_0035f01c;
extern "C" s8* D_0035f230;
// why: accepted call sites declare this with a variadic list; the original passes one word in a0, so the list is written out
extern "C" s32 func_002570a0(s32);
extern "C" u32 func_00287bc0(void);
// why: extern "C" because the accepted asm-label definition form is not linkable in the isolated probe: the probe linker script defines only the plain symbol
extern "C" s32 func_0028b040(s16* object);

// why: s32 return: every exit leaves the function's own index (or -1) in v0

s32 func_0027af58() {
    s32 limit;
    s32 total;
    s32 result;
    s32 index;

    if (func_00287bc0() == 16) {
        limit = func_0028b040(D_0035f01c);
    } else {
        limit = func_002570a0(16);
    }
    total = 0;
    result = -1;
    for (index = 0; index < 4; index++) {
        total += D_0035f230[index + 8];
        if (limit < total) {
            result = index;
            break;
        }
    }
    return result;
}
