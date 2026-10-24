#include "../common/types.h"
extern "C" u16 func_001bc010(...);
extern "C" u32 func_0017df58(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_0017e3b8(...);

u32 func_001c9ab8(void) {
    register u32 result asm("$15"); // why: original keeps the result in t7 and copies it to v0 in the epilogue
    if (func_001bc010() == 0) {
        s32 index = 0;
        do {
            u32 object = func_0017df58(index);
            index++;
            if (!func_0019ba60(object)) {
                goto fail;
            }
            if (!func_0017e3b8(object)) {
                goto fail;
            }
        } while (index < 2);
    }
    result = 1;
    goto done;
fail:
    result = 0;
done:
    return result;
}
