#include "../common/types.h"
extern "C" u32 D_0036c908[];

s32 func_00186110(s32 unused, u8* object) {
    u32 index = object[36];
    if (index >= 10) {
        return 0;
    }
    // why: switch table is the global D_0036c908; the object-local table cannot be linked in the probe
    goto *(void*)D_0036c908[index];
    return 1;
}
