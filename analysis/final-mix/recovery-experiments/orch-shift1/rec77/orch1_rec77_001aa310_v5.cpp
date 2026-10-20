#include "../common/types.h"

extern "C" f32 D_0036d6a4[];
extern "C" s32 func_001ab820(u32);
extern "C" f32 func_00192fb8(u32*);

u8* func_001aa310(u32 unused, u32* object, u8* base) {
    f32 count = (f32)func_001ab820(object[0]);
    f32 scale = func_00192fb8(object + 8);
    // why: volatile read keeps the table address formed before the load
    s32 index = (s32)(count * scale + *(volatile f32*)D_0036d6a4);
    return base + index * 16;
}
