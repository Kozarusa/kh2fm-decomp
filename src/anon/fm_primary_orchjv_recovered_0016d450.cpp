#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_004f62f0;
extern "C" kn::FVector D_004f6300;
extern "C" u8 D_0016e888[];
extern "C" void func_002fd188(u8*);

void func_0016d450(u32* object) {
    kn::FVector* source = (kn::FVector*)object[0];
    kn::FVector temp;
    f32 scale;
    if (D_004f62f0 == 0) {
        D_004f62f0 = 1;
        func_002fd188(D_0016e888);
    }
    scale = *(f32*)&object[1];
    // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp (frame shape from accepted sibling fm_primary_orchit_recovered_0016d4d0.cpp)
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&temp), "r"(source), "f"(scale) : "$8", "memory");
    D_004f6300 = temp;
    object[0] = (u32)&D_004f6300;
}
