#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    f32 v[4];
};
typedef u8* (*BaseGetter)(u32);
extern "C" f32 D_00349e10;
extern "C" f32 D_00351fd8;
extern "C" f32 D_0036e148;
extern "C" u32 func_002d1260(void);        // copied from accepted caller fm_primary_sixword_recovered_002e7c78.cpp
extern "C" s32 func_0019ba60(u8*);         // copied from accepted caller fm_primary_orchkh_recovered_001c9860.cpp
extern "C" f32 func_001cbf50(f32);         // matches accepted definition fm_primary_orchkc_recovered_001cbf50.cpp
extern "C" f32 func_002f87c0(f32);         // copied from accepted caller fm_primary_orchjs_recovered_001b0580.cpp
// why: only placeholder declarations exist (auto80/tiny_auto80); argument in $f12 and result stored from $f0 as a float
extern "C" f32 func_002f8960(f32);

s32 func_001cad60(u8* object) {
    f32 zero = 0.0f;
    s32 result;
    u32 player = func_002d1260();
    f32 timer = *(f32*)(object + 0x40) - D_00349e10;
    *(f32*)(object + 0x40) = timer;
    if (timer <= zero || func_0019ba60((u8*)player) == 0) {
        result = 0;
    } else {
        *(f32*)(object + 0xa0) = *(f32*)(object + 0xa0) + *(f32*)(object + 0xa8) * D_00349e10;
        f32 ratio = *(f32*)(object + 0x40) / D_00351fd8;
        f32 angle = func_001cbf50(*(f32*)(object + 0xa0));
        *(f32*)(object + 0x0) = func_002f87c0(angle);
        *(f32*)(object + 0x4) = func_002f8960(angle);
        *(f32*)(object + 0x8) = zero;
        // why: VU macro scale by a float broadcast, same text as accepted sibling fm_primary_orchix_recovered_0018be00.cpp
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(object), "f"(*(f32*)(object + 0xac) * ratio) : "$8", "memory");
        Vector offset;
        // why: lq/sq copy primitive through t0, same text as accepted sibling fm_primary_orchix_recovered_0018be00.cpp
        asm volatile("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&offset), "r"(object + 0x70) : "$8", "memory");
        // why: VU macro scale by a float broadcast, same text as accepted sibling fm_primary_orchix_recovered_0018be00.cpp
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&offset), "f"(offset.v[3] * ratio) : "$8", "memory");
        u8* base = (*(BaseGetter**)player)[40](player);
        Vector position;
        // why: VU macro three-operand vector add, same text as accepted sibling fm_primary_orchia_recovered_00159d30.cpp
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&position), "r"(&offset), "r"(base + 0x30) : "memory");
        // why: VU macro vector add in place, same text as accepted sibling fm_primary_orchix_recovered_0018be00.cpp
        asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(object), "r"(&position) : "memory");
        f32* factor = &D_0036e148;
        asm("" : "+r"(factor)); // why: original forms the full address before the load
        result = 1;
        *(u8*)(object + 0x16) = (s32)(ratio * *factor);
    }
    return result;
}
