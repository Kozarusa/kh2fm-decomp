#include "../common/types.h"
#include "../kn/fvector.hpp"
// Vector getter called through the target's vtable slot at +0xc.
typedef kn::FVector (*VectorGetter)(u8*, s32);
// func_0016af58 is declared variadic in accepted sources; here it builds a direction from an id.
typedef kn::FVector (*DirectionFromId)(s32);
extern "C" f32 D_0036ccd4;
extern "C" u64 func_0016af58(...);
extern "C" kn::FVector func_0017d538(u32, f32);
extern "C" f32 func_002f87c0(f32);

// Returns 1 when the target has no turn range or lies inside the facing cone, 0 otherwise.

s32 func_0018e698(u8** object, u8** target) {
    u16 amount;
    kn::FVector forward;
    amount = *(u8*)(*(u8**)(*object + 0x28) + 0x22);
    if (amount == 0) {
        return 1;
    }
    // why: the original forms &D_0036ccd4 in t6 with lui/addiu before the sp+16 address; unpinned (v9) it lands in t7 after the cvt.s.w (5 words)
    register f32* pointer asm("$14") = &D_0036ccd4;
    // why: keeps the full address in t6 instead of folding the low half into lwc1; without it (v7) the block order shifts (59 words)
    asm("" : "+r"(pointer));
    // why: the original keeps the angle step in callee-saved $f21 and the cone limit in $f20; unpinned (v8) the two swap (5 words)
    register f32 unit asm("$f21") = *pointer;
    f32 limit = -func_002f87c0(amount * unit);
    s32 id = *(s32*)(*object + 0xc);
    forward = ((DirectionFromId)func_0016af58)(id);
    // why: the original reloads *object and the data pointer through t6/t7 after the calls; unpinned (v6) they shift to t5/t6 (8 words)
    register u8* data asm("$15") = *(u8**)(*object + 0x28);
    // why: the signed turn count is loaded into t7 over the data pointer, as in the original lb t7,35(t7)
    register s32 turn asm("$15") = *(s8*)(data + 0x23);
    if (turn) {
        // why: unused value; it makes 2*turn reuse t7 (sll t7,t7,1) and orders mtc1 after move a0,s1 as in the original; without it (v2-v4) the product goes to t5 (3 words)
        s32 doubled = (f32)((u64)turn * 2);
        forward = func_0017d538((u32)&forward, 2 * turn * unit);
    }
    f32 dot;
    u8* handler = *target;
    const kn::FVector& current = (*(VectorGetter*)(*(u8**)handler + 0xc))(handler, *(s32*)(*object + 0xc));
    // why: VU dot product of the xyz lanes; identical text to accepted fm_primary_orchiu_recovered_0016da20.cpp and fm_primary_orchjx_recovered_0018a420.cpp; $8 (t0) is the qmfc2/mtc1 transfer register
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0" : "=f"(dot) : "r"(&current), "r"(&forward) : "$8", "memory");
    if (dot < limit) {
        return 1;
    }
    return 0;
}
