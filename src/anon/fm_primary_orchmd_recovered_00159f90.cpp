#include "../common/types.h"
extern "C" f32 D_0034aa44;

s32 func_00159f90(s32 unused, u32 flags) {
    D_0034aa44 = 0;
    if (flags & 4) {
        D_0034aa44 = 0.34906584f;
    } else if (flags & 8) {
        D_0034aa44 = -0.34906584f;
    }
    return 1;
}
