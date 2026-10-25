#include "../common/types.h"
extern "C" s32 D_003617ec;
extern "C" u32 D_003617f0;
extern "C" u8 D_003617f8;
extern "C" u8 D_002bd838[];   // why: callback code address passed as the fifth argument (t0)
// why: copied from the recovered call site fm_primary_orchli_recovered_00292fe8.cpp
extern "C" void func_00168410(u32, s32, s32, u16, s32, s32);
// why: no recovered declaration; a0 is the object base read here, v0 is the s32 status it computes
extern "C" s32 func_002b8ac0(s32);

void func_002bd870() {
    if (func_002b8ac0(D_003617ec) != 0 && D_003617f8 == 0 && D_003617f0 != 0) {
        func_00168410(D_003617f0, D_003617ec, *(s32*)(D_003617ec + 0x4802c), 16, (s32)D_002bd838, 0);
        D_003617f8 = 1;
    }
}
