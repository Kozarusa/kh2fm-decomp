#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef unsigned int Quad __attribute__((mode(TI)));
// why: the accepted definition of func_0019c8a8 is void(void), but the original passes the object in a0 and tests v0 after the call
typedef u32 (*TestFn)(u8*);
extern "C" s32 D_0034e948;
extern "C" u32 D_0034f240;
extern "C" f32 D_0036cd68;
extern "C" bool func_0019ba60(...);
extern "C" s32 func_0016c028(s32);
extern "C" u8* func_00185da8(u8*);
extern "C" void func_0019c8a8(void); // why: accepted C++ definition in fm_resume_recovered_00.cpp; C++ linkage does not link to the registry name func_0019c8a8 in the isolated probe

void func_00191cd8(void) {
    s32 owner = D_0034e948;
    D_0034f240 &= 0xfffeffff;
    if (func_0019ba60(owner) == 0) {
        return;
    }
    kn::FVector origin;
    // why: binds the quad temporary to t0 as in the original, pattern from accepted fm_primary_orchbc_recovered_001786e0.cpp
    register Quad copy asm("$8") = *(volatile Quad*)func_0016c028(owner);
    *(Quad*)&origin = copy;
    asm volatile("" ::: "memory"); // why: keeps the quad copy directly after the call
    f32* pointer = &D_0036cd68;
    asm("" : "+r"(pointer)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    f32 limit = *pointer;
    u8* object = 0;
    while ((object = func_00185da8(object)) != 0) {
        if ((*(u32*)(object + 0x588) & 0x400) != 0) {
            D_0034f240 |= 0x10000;
            return;
        }
        if ((*(s32*)(object + 0x3b0) ^ 2) != 0) {
            continue;
        }
        // why: call through TestFn because the original passes the object and tests v0 (see the typedef)
        if (((TestFn)func_0019c8a8)(object) != 0) {
            D_0034f240 |= 0x10000;
            return;
        }
        Quad difference;
        // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjk_recovered_00191218.cpp and fm_primary_orchjq_recovered_0019bfd0.cpp
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&difference), "r"(func_0016c028((s32)object)), "r"(&origin) : "memory");
        ((s32*)&difference)[1] = 0;
        f32 length;
        // why: VU macro xyz length, same sequence as accepted fm_primary_orchjk_recovered_00191218.cpp and fm_primary_orchjq_recovered_0019bfd0.cpp
        asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                     : "=f"(length) : "r"(&difference) : "$8", "memory");
        if (length < limit) {
            D_0034f240 |= 0x10000;
            return;
        }
    }
}
