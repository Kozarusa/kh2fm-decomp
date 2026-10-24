#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_004f6310;
extern "C" kn::FVector D_004f6320;
extern "C" u8 D_0016e890[];
extern "C" void func_002fd188(u8*);

void func_0016d4d0(u32* object) {
    kn::FVector* source = (kn::FVector*)object[0];
    kn::FVector temp;
    f32 divisor;
    if (D_004f6310 == 0) {
        D_004f6310 = 1;
        func_002fd188(D_0016e890);
    }
    divisor = *(f32*)&object[1];
    // why: VU0 macro vector divide by scalar, same sequence as accepted func_002f3e90
    asm volatile(
        "lqc2 $vf1,0(%1);"
        "mfc1 $8,%2;"
        "qmtc2 $8,$vf2;"
        "vdiv Q,$vf0w,$vf2x;"
        "vwaitq;"
        "vmulq.xyzw $vf1,$vf1,Q;"
        "sqc2 $vf1,0(%0)" : : "r"(&temp), "r"(source), "f"(divisor) : "$8", "memory");
    D_004f6320 = temp;
    object[0] = (u32)&D_004f6320;
}
