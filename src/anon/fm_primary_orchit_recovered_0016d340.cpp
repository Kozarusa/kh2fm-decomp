#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_004f62b0;
extern "C" kn::FVector D_004f62c0;
extern "C" u8 D_0016e878[];
extern "C" void func_002fd188(u8*);

void func_0016d340(u32* object) {
    kn::FVector* left = (kn::FVector*)object[0];
    kn::FVector* right = (kn::FVector*)object[1];
    if (D_004f62b0 == 0) {
        D_004f62b0 = 1;
        func_002fd188(D_0016e878);
    }
    kn::FVector temp;
    // why: VU0 macro vector add, same sequence as accepted 00140500/001604f8
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&temp), "r"(left), "r"(right) : "memory");
    D_004f62c0 = temp;
    object[0] = (u32)&D_004f62c0;
}
