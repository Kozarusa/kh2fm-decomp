#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 func_0019bb98(u8*);
// why: type of the accepted C++ definition in auto200_999.cpp; extern "C" because C++ linkage fails the isolated probe link
extern "C" f32 func_0016a0a0(u32 a0);
// why: type of the accepted C++ definition in fm_primary_queuezeta_recovered_001b7958.cpp; extern "C" because C++ linkage fails the isolated probe link
extern "C" void func_001b7958(u8* object, const f32* translation);

// why: void per DEVIATIONS #36; exits: both-ready paths leave the direct func_0019bb98 result, the two
// func_001b7958 tails are stale-b (void callee), and the quotient left in $f0 crossed the func_001b7958 call

void func_001b7b10(u8* self, u8* other, kn::FVector* source, kn::FVector* target) {
    if (func_0019bb98(*(u8**)(other + 4)) != 0) {
        if (func_0019bb98(*(u8**)(self + 4)) != 0) {
            *target = *source;
        }
        return;
    }
    if (func_0019bb98(*(u8**)(self + 4)) != 0) {
        u8* base = *(u8**)(other + 4) + 0x870;
        // why: VU macro vector add, text identical to accepted func_001b7958
        asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(base), "r"(target) : "memory");
        func_001b7958(other, (const f32*)target);
        // why: VU macro zero-fill of a 16-byte vector, text identical to accepted func_0016adc8
        asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(target) : "memory");
        return;
    }
    f32 selfValue = func_0016a0a0(*(u32*)(self + 4));
    f32 otherValue = func_0016a0a0(*(u32*)(other + 4));
    kn::FVector part;
    kn::FVector scaled;
    // why: VU macro scale by a float broadcast, text identical to accepted func_00193be8; the trailing directives emit nothing and keep gas from moving sqc2 into the branch delay slot
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&scaled), "r"(target), "f"(selfValue / (selfValue + otherValue)) : "$8", "memory");
    part = scaled;
    // why: VU macro scale by a float broadcast, text identical to accepted func_0016d760
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&scaled), "r"(&part), "f"(otherValue / selfValue) : "$8", "memory");
    *target = scaled;
    u8* base = *(u8**)(other + 4) + 0x870;
    // why: VU macro vector add, text identical to accepted func_001b7958
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(base), "r"(&part) : "memory");
    func_001b7958(other, (const f32*)&part);
}
