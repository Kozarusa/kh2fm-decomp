#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036c988;
extern "C" f32 D_0036c98c;
extern "C" f32 D_00349e10;
extern "C" f32 func_002f8b30(f32, f32);

kn::FVector* func_00186b90(kn::FVector* out, u8* object) {
    f32 zero = 0.0f;
    f32 power = *(f32*)(object + 0xadc);
    s32 active = zero < power;
    asm("" : "+r"(active)); // why: original materialises the compare flag and masks it with andi 0xff before the test
    if ((u8)active) {
        f32* limit = &D_0036c988;
        asm("" : "+r"(limit)); // why: original forms the full address before the load
        if (power < *limit) {
            *(f32*)(object + 0xadc) = zero;
        } else {
            kn::FVector scaled;
            // why: VU macro scale by a float broadcast, same sequence as accepted sibling fm_primary_orchjj_recovered_0018d840.cpp
            asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                         : : "r"(&scaled), "r"(object + 0xad0), "f"(power * D_00349e10) : "$8", "memory");
            *out = scaled;
            f32* base = &D_0036c98c;
            asm("" : "+r"(base)); // why: original forms the full address before the load
            *(f32*)(object + 0xadc) = *(f32*)(object + 0xadc) * func_002f8b30(*base, D_00349e10);
            return out;
        }
    }
    // why: VU macro zero-vector store, same sequence as accepted sibling fm_primary_orchfj_recovered_002c17d8.cpp
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(out) : "memory");
    return out;
}
