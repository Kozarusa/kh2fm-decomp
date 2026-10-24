#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 func_002f8870(f32);
extern "C" f32 D_0036c8a8;
extern "C" f32 D_00349e10;

// Preserve original registry aliases.
kn::FVector* func_00184540(kn::FVector* out, u8* object, f32 blend, f32 scale) asm("_Z13func_00184540jjff");

kn::FVector* func_00184540(kn::FVector* out, u8* object, f32 blend, f32 scale) {
    kn::FVector result;
    kn::FVector mixed;
    if (blend != 0.0f) {
        const f32* limit_address = &D_0036c8a8;
        asm("" : "+r"(limit_address)); // why: original forms the full address before the lwc1
        register f32 limit asm("$f22") = *limit_address; // why: original keeps the limit in f22 across the calls
        if (func_002f8870(*(f32*)(object + 0x20)) < limit) {
            if (func_002f8870(*(f32*)(object + 0x24)) < limit) {
                func_002f8870(*(f32*)(object + 0x28));
            }
        }
    }
    f32 weight = *(f32*)(object + 0x1c);
    if (0.0f < weight) {
        kn::FVector scaled;
        // why: VU0 macro vector times scalar, same sequence as accepted 00159d30
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%1)"
                     : : "r"(object + 0x10), "r"(&scaled), "f"(weight) : "$8", "memory");
        // why: VU0 macro linear blend, same sequence as fm_fallback_vector lerp; noreorder keeps the sqc2 out of the branch delay slot
        asm volatile(".set noreorder; lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); mfc1 $8,%3; qmtc2 $8,$vf3; vaddw.x $vf4,$vf0,$vf0w; vsub.x $vf4,$vf4,$vf3; vmulax.xyzw ACC,$vf2,$vf3x; vmaddx.xyzw $vf1,$vf1,$vf4x; sqc2 $vf1,0(%0); .set reorder"
                     : : "r"(&mixed), "r"(&scaled), "r"(object + 0x20), "f"(blend) : "$8", "memory");
        result = mixed;
    } else {
        // why: VU0 macro vector times scalar, same sequence as accepted 00159d30; noreorder keeps the sqc2 out of the branch delay slot
        asm volatile(".set noreorder; lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0); .set reorder"
                     : : "r"(&mixed), "r"(object + 0x20), "f"(scale) : "$8", "memory");
        if (&result != &mixed) {
            // why: lq/sq copy primitive as in kn::FVector; noreorder keeps the sq out of the following branch delay slot
            asm(".set noreorder; lq $8,0(%1); sq $8,0(%0); .set reorder" : : "r"(&result), "r"(&mixed) : "$8", "memory");
        }
    }
    *(kn::FVector*)(object + 0x20) = result;
    // why: VU0 macro vector times scalar, same sequence as accepted 00159d30
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(out), "r"(&result), "f"(D_00349e10) : "$8", "memory");
    return out;
}
