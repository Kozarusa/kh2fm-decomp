#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_004f62d0;
extern "C" kn::FVector D_004f62e0;
extern "C" u8 D_0016e880[];
extern "C" void func_002fd188(u8*);

void func_0016d3c8(u32* object) {
    kn::FVector* first = (kn::FVector*)object[0];
    kn::FVector* second = (kn::FVector*)object[1];
    if (D_004f62d0 == 0) {
        D_004f62d0 = 1;
        func_002fd188(D_0016e880);
    }
    kn::FVector difference;
    // why: VU macro vector subtract, pattern from accepted siblings 00159d30 and 00165a10
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0"
                 : "=m"(difference) : "r"(first), "r"(second) : "memory");
    D_004f62e0 = difference;
    object[0] = (u32)&D_004f62e0;
}
