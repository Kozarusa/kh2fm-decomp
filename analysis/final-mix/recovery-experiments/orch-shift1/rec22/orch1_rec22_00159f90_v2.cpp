#include "../common/types.h"
extern "C" f32 D_0034aa44;
extern "C" f32 D_0036b380;
extern "C" f32 D_0036b384;

s32 func_00159f90(s32 unused, u32 flags) {
    f32* pointer;
    if ((flags & 4) == 0) {
        if ((flags & 8) == 0) {
            D_0034aa44 = 0;
            return 1;
        }
        pointer = &D_0036b384;
    } else {
        pointer = &D_0036b380;
    }
    D_0034aa44 = *pointer;
    return 1;
}