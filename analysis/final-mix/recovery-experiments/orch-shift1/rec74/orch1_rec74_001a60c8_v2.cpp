#include "../common/types.h"
extern "C" u8 D_00350800[];
extern "C" s32 func_001a6658(s32);
extern "C" u32 func_001bdff0(void);

u32 func_001a60c8(void) {
    s32 index;
    s32* slot = (s32*)(D_00350800 + 40);
    for (index = 0; index < 6; index++) {
        *slot = func_001a6658(index);
        slot += 11;
    }
    return func_001bdff0();
}
