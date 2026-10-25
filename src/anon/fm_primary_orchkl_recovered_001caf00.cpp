#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
typedef u8* (*Getter)(s32);
extern "C" f32 D_00349e10;
extern "C" f32 D_00351fd8;
extern "C" f32 D_00351fe0;
extern "C" f32 D_0036e14c;
extern "C" f32 D_0036e150;
extern "C" u32 func_002d1260(void);
extern "C" bool func_0019ba60(u64);
extern "C" void func_0011b6a8(void*);
// why: no accepted call site of func_0011b768 (kn::FMatrix::rotateZ); matrix pointer in a0 and the angle in $f12, same shape as accepted func_0011b6d8(void*, f32)
extern "C" void func_0011b768(void*, f32);
// why: extern "C" because the accepted definition f32 func_001cbf50(f32) has C++ linkage, which fails the isolated link (same failure as lg334 001ca4a8 v1)
extern "C" f32 func_001cbf50(f32 value);

// why: returns s32 because both exits load an own constant into v0 (0 on the skip paths, 1 on the update path)

// Preserve original registry aliases.
s32 func_001caf00(u8* object) asm("_Z16u_call4_001caf00jjjj");

s32 func_001caf00(u8* object) {
    // why: s32 local so the u64 argument of func_0019ba60 is a plain move (v1: u32 emitted a dsll32/dsrl32 zero extension)
    s32 player = func_002d1260();
    f32 timer = *(f32*)(object + 64) - D_00349e10;
    *(f32*)(object + 64) = timer;
    if (timer <= 0.0f || !func_0019ba60(player)) {
        return 0;
    } else {
        f32 ratio = *(f32*)(object + 64) / D_00351fd8;
        kn::FVector direction;
        Matrix rotation;
        kn::FVector temp;
        // why: lq/sq copy primitive through t0 (operator= adds a self-copy branch the original lacks), same as accepted 0016d760
        asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&direction), "r"(object + 144) : "$8");
        // why: VU macro scale by a float broadcast, same sequence as accepted 0016d760
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&direction), "f"(*(f32*)(object + 156) * ratio) : "$8", "memory");
        const f32* full = &D_0036e14c;
        asm("" : "+r"(full)); // why: original forms the full address with lui+addiu before the lwc1
        f32 one = *full;
        kn::FVector* row = (kn::FVector*)rotation.columns[3];
        ((f32*)&direction)[3] = one;
        func_0011b6a8(&rotation);
        func_0011b768(&rotation, func_001cbf50(D_00351fe0 * (one - ratio)));
        u8* base = ((Getter)(*(u32**)player)[40])(player);
        *row = *(kn::FVector*)(base + 48);
        // why: VU0 macro vector times matrix, same sequence as accepted 00140500
        asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                     : : "r"(&temp), "r"(&direction), "r"(&rotation) : "memory");
        *(kn::FVector*)object = temp;
        const f32* steps = &D_0036e150;
        asm("" : "+r"(steps)); // why: original forms the full address with lui+addiu before the lwc1
        *(u8*)(object + 22) = (s32)(ratio * *steps);
        return 1;
    }
}
