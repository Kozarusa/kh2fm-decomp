#include "../common/types.h"
extern "C" u8 D_0035e359;
extern "C" u8 D_00371300[];
extern "C" u8 D_00371320[];
extern "C" u32 func_00232348();
extern "C" u32 func_002fee78(...);
extern "C" u64 func_002ff538(...);
extern "C" u32 func_002baa08(...);

s32 func_002325f0(u8* object) {
    s32 found = 0;
    if (D_0035e359 == 1) {
        u8 buffer[64];
        u8* name = object + 48;
        func_002fee78(buffer, D_00371300, func_00232348());
        if (func_002ff538(name, buffer, 24) == 0) {
            found = 1;
            func_002baa08(*(s32*)(object + 20), *(s32*)(object + 28), 16383, 0);
        }
        func_002fee78(buffer, D_00371320, func_00232348());
        if (func_002ff538(name, buffer, 24) == 0) {
            found = 1;
            func_002baa08(*(s32*)(object + 20), *(s32*)(object + 28), 16383, 127);
        }
    }
    return found;
}
