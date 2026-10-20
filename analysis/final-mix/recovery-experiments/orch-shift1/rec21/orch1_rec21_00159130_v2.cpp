#include "../common/types.h"
extern "C" f32 D_0036b328[];
extern "C" s32 D_0034a9f0[5];
extern "C" u8* func_00140df0();
extern "C" void func_00141010(f32);

void func_00159130(s32* source) {
    func_00141010(D_0036b328[0]);
    *(s32*)(func_00140df0() + 0x40) = 3;
    D_0034a9f0[0] = source[0];
    D_0034a9f0[1] = source[1];
    D_0034a9f0[2] = source[2];
    D_0034a9f0[3] = source[3];
    D_0034a9f0[4] = source[4];
}

