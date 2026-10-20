#include "../common/types.h"
extern "C" u8* func_0016e920(u32);

u32 func_001997c0(u32* object) {
    u8* data = func_0016e920(*object);
    s32 kind = data[4];
    if (kind == 13) {
        return 1;
    }
    if (kind < 14) {
        if (kind == 4) {
            return 1;
        }
        return 0;
    }
    if (kind == 21) {
        return 1;
    }
    if (kind == 23) {
        return 1;
    }
    return 0;
}
