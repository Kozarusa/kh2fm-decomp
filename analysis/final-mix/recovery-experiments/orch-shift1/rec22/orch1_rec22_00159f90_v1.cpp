#include "../common/types.h"
extern "C" f32 D_0034aa44;
extern "C" f32 D_0036b380;
extern "C" f32 D_0036b384;

s32 func_00159f90(s32 unused, u32 flags) {
    D_0034aa44 = 0;
    if (flags & 4) {
        D_0034aa44 = D_0036b380;
        return 1;
    }
    if (flags & 8) {
        D_0034aa44 = D_0036b384;
    }
    return 1;
}