#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8* D_00352130;
extern "C" f32 D_00349e10;
// why: no accepted source declares it; parameters derived from registers (a0 result vector, a1 owner, a2 object), it returns its first argument (move v0,s1)
extern "C" kn::FVector* func_001d2e68(kn::FVector*, u8*, u8*);
// why: no accepted source declares it; parameters derived from registers (a0 owner, $f12 w), its $f0 result is passed on as $f12
extern "C" f32 func_001d3000(u8*, f32);
extern "C" void func_00183768(f32,s32,s32);              // copied from accepted caller fm_primary_sixword_recovered_00174168.cpp
extern "C" void func_0016b010(u8*, f32*);               // matches the accepted void definition in fm_more_recovered.cpp
extern "C" u32 func_00190140(...);                      // copied from accepted caller fm_primary_fourword_recovered_0013f498.cpp
extern "C" kn::FVector* func_00190388(kn::FVector*, s32*); // copied from accepted caller fm_primary_orchkh_recovered_0019d260.cpp
extern "C" u64 func_0016bda8(...);                      // copied from accepted caller fm_primary_orchji_recovered_002c5fb8.cpp
extern "C" void func_0017f488(u8*, s32, f32, f32);      // copied from accepted caller fm_primary_orchfj_recovered_002c17d8.cpp
extern "C" void func_0017f5e0(u8*, s32, f32, f32, void*); // copied from accepted caller fm_primary_orchiv_recovered_00187018.cpp
extern "C" void func_0016bd60(u32, s32);                // copied from accepted caller fm_primary_animation_recovered.cpp

// why: void per DEVIATIONS #36; exit A (timer > 0): the last call is void func_0016b010 (it stores atan2f's $f0 and writes no v0 after), so v0 is stale-b and $f0 is this function's own mtc1 zero temporary; exit B: func_0016bd60 does a jalr and then tail-calls accepted-void 0016bd10 (no v0 write after its jalr), so v0 is stale-b

void func_001d2c78(u8* owner, u8* object) {
    u8* settings = D_00352130;
    kn::FVector base;
    kn::FVector temporary;
    kn::FVector* position = (kn::FVector*)(object + 32);
    func_001d2e68(&base, owner, object);
    f32 value = func_001d3000(owner, *(f32*)&base.w);
    func_00183768(value, (s32)object, (s32)&base);
    // why: lq/sq copy primitive without the self-assignment guard, plain Quad copy was scheduled apart; same asm as kn::FVector::operator=
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&temporary), "r"(position) : "$8", "memory");
    func_0016b010(object, (f32*)&temporary);
    s32* target = (s32*)(object + 0x9f4);
    f32 timer = *(f32*)(object + 0xb68) - D_00349e10;
    *(f32*)(object + 0xb68) = timer;
    if (timer <= 0.0f) {
        if (func_00190140(target)) {
            kn::FVector goal;
            kn::FVector origin;
            func_00190388(&goal, target);
            func_0016bda8((Quad*)&origin, (u32)object);
            register u32 spare asm("$17"); // why: original saves s1 (as a word) but never uses it, so every long-lived value sits one s register higher; empty "=r" definition pattern as in accepted fm_primary_orchdo_recovered_00220c88.cpp (no accepted source binds $17 this way)
            asm volatile("" : "=r"(spare)); // why: marks s1 as written here without emitting an instruction
            // why: VU macro vector subtract, pattern from accepted sibling func_0018d840
            asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                         : : "r"(&temporary), "r"(&goal), "r"(&origin) : "memory");
            register f32 length asm("$f1"); // why: original moves the unused length into $f1
            // why: VU macro normalize xyz in place, pattern from accepted sibling func_0018d840
            asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                         : "=f"(length) : "r"(&temporary) : "$8", "memory");
            // why: VU macro scale by a float broadcast, pattern from accepted sibling func_0018d840
            asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                         : : "r"(&goal), "r"(&temporary), "f"(*(f32*)(settings + 0x118)) : "$8", "memory");
            *position = goal;
        }
        u8* motion = object + 0x140;
        func_0017f488(motion, 153, 0.0f, 0.0f);
        func_0017f5e0(motion, 0, 0.0f, 0.0f, 0);
        func_0016bd60((u32)object, 29);
    }
}
