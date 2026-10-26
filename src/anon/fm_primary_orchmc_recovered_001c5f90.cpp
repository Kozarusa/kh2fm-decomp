#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 D_01d498b0;
extern "C" u8 D_00352a60[];
extern "C" u8 D_01d49870[];
// why: the only accepted source is the tiny_more.cpp definition u32 func_001c5f78(u32 a0,u32 a1,u32 a2,u32 a3), which reads only a0 ((void) on a1-a3);
// the original sets only a0 before this jal, so passing four arguments would add a1-a3 moves; the u32 return and a0 type are kept from that definition,
// and extern "C" binds the plain registry symbol func_001c5f78 (no accepted call site exists)
extern "C" u32 func_001c5f78(u32);
// why: varargs declaration copied from accepted fm_primary_threewordnext_recovered_0019e6e8.cpp; the typed (s32) form truncates the u64 cursor with dsll32/dsra32 (v2)
extern "C" u64 func_001b9bc8(...);
// why: varargs declaration copied from accepted fm_primary_fiveword_recovered_00171a40.cpp; the typed (s32) form truncates the u64 cursor with dsll32/dsra32 (v3)
extern "C" u32 func_0016a020(...);
extern "C" bool func_00197920(void);
extern "C" void func_001dbb38();
extern "C" u64 func_001dbe78(u8* object, f32* direction);

u64 func_001c5f90(u8* object) {
    kn::FVector direction;
    kn::FVector temp;
    u64 result = 0;
    if (1000 - D_01d498b0 < 300) {
        *(s32*)(object + 88) = 1000;
        func_001dbb38();
    } else if (func_001c5f78((u32)object) != 0) {
        s32 count = 0;
        while ((result = func_001b9bc8(result)) != 0) {
            if (func_0016a020(result) == 1469) {
                count++;
                if (count >= 2) {
                    return 0;
                }
            }
        }
        func_001dbb38();
    }
    if (func_00197920()) {
        // why: VU macro vector subtract, same text as accepted fm_primary_orchjk_recovered_0018e8f0.cpp; trailing noreorder keeps the sqc2 out of the branch delay slot (v4)
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                     : : "r"(&temp), "r"(D_00352a60), "r"(object) : "memory");
        direction = temp;
        f32 length;
        // why: VU macro normalize xyz in place returning the length, same sequence as accepted fm_primary_orchjq_recovered_001cdbc8.cpp
        asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                     : "=f"(length) : "r"(&direction) : "$8", "memory");
        if (400.0f < length) {
            result = func_001dbe78(object, (f32*)&direction);
        }
    } else {
        f32 factor = -1.0f;
        // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchjj_recovered_0018d840.cpp
        asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&direction), "r"(D_01d49870), "f"(factor) : "$8", "memory");
        result = func_001dbe78(object, (f32*)&direction);
    }
    return result;
}
