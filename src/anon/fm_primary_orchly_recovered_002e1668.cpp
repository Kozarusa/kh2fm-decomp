#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" bool func_00197920(u8*);
extern "C" kn::FVector* func_0016c028(u8*);
extern "C" void func_002e1440(u8*, kn::FVector*, f32*, f32*);

void func_002e1668(u8* object, u8* owner, kn::FVector* offset, kn::FVector* position) {
    if (func_00197920(object)) {
        return;
    }
    if (*(u8*)(object + 88) == 0) {
        return;
    }
    if ((*(u32*)(owner + 1416) & 0x80) == 0) {
        return;
    }
    kn::FVector combined;
    kn::FVector target;
    kn::FVector sum;
    kn::FVector delta;
    kn::FVector* base = func_0016c028(owner);
    // why: VU macro vector add (lqc2/lqc2/vadd/sqc2); the original uses the .wxyz spelling that accepted func_002c7060 documents for vsub; no plain C form exists
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&target), "r"(base), "r"(offset) : "memory");
    // why: VU macro vector add of the second offset into a separate vector (same shape as above)
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&combined), "r"(&target), "r"(position) : "memory");
    // why: lq/sq copy primitive through t0 without a self-assignment test; measured plain forms: kn::FVector::operator= 43 words (v1, adds a beq the original lacks), Quad typedef copy 5 words (v3)
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&target), "r"(&combined) : "$8", "memory");
    func_002e1440(object, &target, (f32*)(object + 208), (f32*)(object + 224));
    // why: VU macro vector subtract, text copied from accepted func_002c7060 (fm_primary_orchlt_recovered_002c7060.cpp)
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&delta), "r"(&target), "r"(&combined) : "memory");
    // why: VU macro vector add (same shape as above)
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&sum), "r"(&delta), "r"(position) : "memory");
    *position = sum;
}
