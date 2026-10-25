#include "../common/types.h"
extern "C" u32 func_00313b80(f32);
extern "C" s32 func_003142e0(s32, u32);
extern "C" bool func_001688b8(void);
extern "C" s32 func_00292a90(s32);
// why: no recovered source calls this; derived from registers (a0 the halfword list address, a1 the count; its loop reads lh entries)
extern "C" void func_00292b40(s16*, s32);
extern "C" f32 D_0035f294;
extern "C" f32 D_00349e10;
extern "C" s16 D_0035f280;
extern "C" u8 D_0035f298;

// why: ruling #36 void: the D_0035f294 <= 0 exit leaves the untouched entry v0 (and no callee f0); the other exits leave direct integer results of func_003142e0, func_001688b8, func_00292a90 or func_00292b40, none a float

void func_00281d48(void) {
    f32 zero = 0.0f;
    f32 value = D_0035f294;
    if (value <= zero) return;
    if (zero < value) {
        D_0035f294 = value - D_00349e10;
    }
    register u32 low asm("$17") = 0; // why: original keeps the zero second compare operand in s1 across both compares
    asm("" : "+r"(low)); // why: original keeps the zero second compare operand in s1 across both compares
    if (func_003142e0(func_00313b80(D_0035f294), low) < 0) {
        D_0035f294 = zero;
    }
    if (func_003142e0(func_00313b80(D_0035f294), low) > 0) return;
    if (func_001688b8() != 0) return;
    if (func_00292a90(D_0035f280) == 0) {
        func_00292b40(&D_0035f280, 1);
    }
    D_0035f298 = 1;
}
