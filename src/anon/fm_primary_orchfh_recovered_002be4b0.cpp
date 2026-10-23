#include "../common/types.h"
extern "C" u8 D_00374fe8[];
extern "C" u8 D_00375000[];
extern "C" u8* D_0033caf4;
extern "C" u32 func_00105c30(...);
extern "C" u32 func_002fee78(u32, u32, u32, u32);
extern "C" u32 func_00170518(u32, s32, u32);
extern "C" u32 func_00170888(u32);

u32 func_002be4b0(u32* object) {
    u8* target;
    if (func_00105c30() != 8) {
        target = D_0033caf4;
    } else {
        target = D_00375000;
    }
    u32* name = object + 16;
    func_002fee78((u32)name, (u32)D_00374fe8, (u32)target, *object);
    func_00170518((u32)name, -200, 0);
    return func_00170888(0);
}
