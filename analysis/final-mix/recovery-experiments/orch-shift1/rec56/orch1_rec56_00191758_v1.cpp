#include "../common/types.h"
extern "C" s32 D_0034f240;
extern "C" f32 D_0036cd58;
extern "C" f32 D_0036cd5c;
extern "C" f32 D_01c6195c;
extern "C" s32 D_01c61960;
extern "C" f32 D_01c61964;
extern "C" void func_00191938(u32);
extern "C" void func_00191bf0(f32);

void func_00191758() {
    D_0034f240 = 0;
    func_00191938(0);
    D_01c61960 = 0;
    D_01c6195c = D_0036cd5c;
    D_01c61964 = D_0036cd58;
    func_00191bf0(D_0036cd58);
}