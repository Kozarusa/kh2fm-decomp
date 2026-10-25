#include "../common/types.h"
extern "C" f32 D_0034aa84;
extern "C" void func_00141010(f32);
extern "C" u8* func_00140df0();
extern "C" s32 func_00140dc0();
extern "C" s32 func_0015a6c8(u32*);

s32 func_0015a638(u32* target) {
    func_00141010(30.0f);
    u8* camera = func_00140df0();
    camera[59] = 1;
    s32 mode = func_00140dc0();
    if (mode == 6 || mode == 8) return mode;
    f32 radius = *(f32*)(camera + 72);
    *(s32*)(camera + 64) = 2;
    D_0034aa84 = radius;
    return func_0015a6c8(target);
}
