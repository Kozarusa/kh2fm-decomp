#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u8* D_0034e948;
extern "C" kn::FVector D_00362e70;
extern "C" bool func_00197920(u8*);
extern "C" void func_002e2728(u8*, s32, u8);
extern "C" void func_002e24e0(u8*);
// why: the accepted C++ alias declaration of func_0016ace0 fails the isolated link with an unresolved set_pos reference; extern "C" resolves in the full build via alias generation (same form as accepted func_002c7060)
extern "C" u32 func_0016ace0(u8* object, const kn::FVector& vector);

// Preserve original registry aliases.
void func_002e2440(u8* object) asm("_Z16wtarget_002e2440jjjj");

void func_002e2440(u8* object) {
    if (func_00197920(object)) {
        return;
    }
    s32 index = *(s32*)(object + 276);
    if (index >= 0) {
        func_002e2728(object, index, *(u8*)(object + 280));
        *(s32*)(object + 276) = -1;
    }
    // why: VU macro zero-fill of the vector, same asm text as accepted func_001bf930 (fm_primary_orchjz_recovered_001bf930.cpp)
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(object + 240) : "memory");
    func_002e24e0(object);
    if (*(u8*)(object + 268) != 0) {
        kn::FVector position;
        // why: lq/sq copy primitive through t0 without a self-assignment test; measured plain forms: kn::FVector::operator= 21 words differ (v1, adds a beq the original lacks), Quad typedef copy 21 words differ (v2)
        asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&position), "r"(object + 224) : "$8", "memory");
        // why: VU macro vector add (lqc2/lqc2/vadd/sqc2), .wxyz spelling as in accepted func_002c7060 for vsub; no plain C form exists
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&position), "r"(&position), "r"(&D_00362e70) : "memory");
        func_0016ace0(D_0034e948, position);
        *(u8*)(object + 268) = 0;
    }
}
