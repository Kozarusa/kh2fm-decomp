#include "../common/types.h"
extern "C" float *func_002d5c20(float *vector); // why: exact types from accepted fm_primary_workerthree_recovered_002d5c20.cpp; extern "C" because its C++ linkage fails the isolated probe link

float* func_002d6e08(float* object, u32 unused, u8* vector) {
    // why: original zero-fills vector with VU macro, exact sequence from accepted sibling 002c5ff8 (fm_primary_orchfk_recovered_002c5ff8.cpp)
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(vector + 0x20) : "memory");
    register u8* second asm("$5") = vector; // why: original passes the third argument in a1 although the callee reads only a0
    asm volatile("" : : "r"(second)); // why: keeps the a1 argument live into the call
    func_002d5c20(object);
    // why: VU macro scale by a float broadcast, sequence from accepted sibling 0016d760 (fm_primary_orchit_recovered_0016d760.cpp)
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(object), "r"(object), "f"(object[3]) : "$8", "memory");
    ((s32*)object)[2] = 0;
    return object;
}
