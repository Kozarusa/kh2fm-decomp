#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u8* D_00351f34;
extern "C" f32 D_0036e0c8;
extern "C" bool func_001ca448(...);                 // copied from accepted caller fm_primary_oneword_recovered_001c8710.cpp
extern "C" void func_0017f540(u8*, s32, f32, f32);  // copied from accepted caller fm_primary_orchbd_recovered_0017c108.cpp
// why: no accepted source declares it; parameter derived from registers (a0 = object), its result is never read
extern "C" void func_001ca4a8(u8*);

// why: void per DEVIATIONS #36; exit A (motion bit set): final call into func_0017f540, declared void at its three accepted call sites, so v0 is stale-b; exit B (bit clear): v0 is the direct func_001ca448 result and $f0 is this function's own normalize length, so the mix allows void
// why: a0 is never read (overwritten by move a0,a1), the caller still passes it

void func_001c9ee8(u8* owner, u8* object) {
    // Animation id passed to func_0017f540: 151 when moving in -x, 152 when moving in +x, 0 otherwise.
    u32 animation = 0;
    if (func_001ca448(object)) {
        if ((*(u32*)(object + 0x7f8) & 4) == 0) {
            func_001ca4a8(object);
        }
    }
    if (0.0f < *(f32*)(object + 0x1c)) {
        if (*(f32*)(object + 0x10) < 0.0f) {
            animation = 151;
        } else if (0.0f < *(f32*)(object + 0x10)) {
            animation = 152;
        }
        // why: byte pointer then typed view; a single cast (v2, v6) puts the sp+16 temporary in t6 instead of the original t7 (4 words)
        u8* base = object + 0x10;
        kn::FVector* velocity = (kn::FVector*)base;
        // why: unused 16-byte local; it reserves the stack slot that gives the original 64-byte frame (without it, v4, the frame is 48 bytes)
        kn::FVector spare;
        kn::FVector scaled;
        // why: VU scale of the direction by speed into a stack temporary; same text as accepted fm_primary_orchiz_recovered_00184540.cpp line 35; $8 (t0) carries the scalar into vf2
        asm volatile(".set noreorder; lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0); .set reorder" : : "r"(&scaled), "r"(velocity), "f"(*(f32*)(object + 0x1c)) : "$8", "memory");
        (void)&spare;
        *velocity = scaled;
    } else {
        // why: VU zero-fill of the velocity vector (2 instructions); noreorder form as in accepted fm_primary_orchbc_recovered_001786e0.cpp
        asm volatile(".set noreorder;" "vsub.xyzw $vf1,$vf0,$vf0;" "sqc2 $vf1,0(%0);" ".set reorder" : : "r"(object + 0x10) : "memory");
    }
    kn::FVector* vector = (kn::FVector*)(object + 0x10);
    f32 length;
    if (func_001ca448(object)) {
        *(f32*)(object + 0x18) = *(f32*)(object + 0x18) + *(f32*)(D_00351f34 + 4);
    } else {
        // why: VU zero-fill of the velocity vector (2 instructions), as in accepted fm_primary_queueeta_recovered_0016adc8.cpp
        asm volatile("vsub.xyzw $vf1,$vf0,$vf0;" "sqc2 $vf1,0(%0)" : : "r"(vector) : "memory");
        // why: VU zero-fill of the vector at +0x20 (2 instructions); noreorder form as in accepted fm_primary_orchbc_recovered_001786e0.cpp
        asm volatile(".set noreorder;" "vsub.xyzw $vf1,$vf0,$vf0;" "sqc2 $vf1,0(%0);" ".set reorder" : : "r"(object + 0x20) : "memory");
    }
    // why: VU normalize returning the length in $f0; identical text to accepted fm_primary_orchit_recovered_0016d760.cpp and fm_primary_orchjj_recovered_0018df90.cpp; $8 (t0) carries Q to the FPU
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)" : "=f"(length) : "r"(vector) : "$8", "memory");
    u8* motion = object + 0x140;
    *(f32*)(object + 0x1c) = length;
    if (*(u32*)(object + 0x160) & 4) {
        f32* rate = &D_0036e0c8;
        // why: keeps &D_0036e0c8 as a full lui/addiu address before the lwc1, as in the original; without it (v8) the low half folds into lwc1 and the code shrinks (29 words)
        asm("" : "+r"(rate));
        func_0017f540(motion, animation, *rate, 0.0f);
    }
}
