#include "../common/types.h"
extern "C" s32 D_01d48da0;
extern "C" bool func_0019baa8(s32);

s32 func_001b9bc8(s32 object) {
    s32 next;
    do {
        if (object == 0) {
            next = D_01d48da0;
        } else {
            next = *(s32*)(object + 0x8b4);
        }
        object = next;
    } while (next != 0 && func_0019baa8(next));
    return next;
}
