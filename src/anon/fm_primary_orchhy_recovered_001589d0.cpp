#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u8* D_004f35a0;

void func_001589d0(u8* object) {
    kn::FVector temp;
    kn::FVector* first = (kn::FVector*)(object + 96);
    u8* matrix = D_004f35a0 + 64;
    // why: VU0 macro vector times matrix, same sequence as accepted 00140500/0013a178/00139c90
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(D_004f35a0 + 2928), "r"(matrix) : "memory");
    *first = temp;
    kn::FVector* second = (kn::FVector*)(object + 128);
    // why: VU0 macro vector times matrix, same sequence as accepted 00140500/0013a178/00139c90
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(D_004f35a0 + 2944), "r"(matrix) : "memory");
    *second = temp;
    *(kn::FVector*)(object + 16) = *first;
    *(kn::FVector*)object = *second;
}
