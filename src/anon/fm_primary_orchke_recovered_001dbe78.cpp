#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 D_003638d0;
extern "C" f32 D_00352ad0;
extern "C" f32 D_0036e7bc;
extern "C" f32 D_0036e7c0;
extern "C" f32 D_0036e7c4;
extern "C" f32 func_002f8ad0(f32, f32);
extern "C" u64 func_0016f000(s32, u8*, f32);
// why: varargs declaration copied from accepted fm_primary_fiveword_recovered_00171a40.cpp; the typed (s32,s32,u32) form truncates the u64 result with dsll32/dsra32 (v1)
extern "C" u32 func_0016c018(...);

u64 func_001dbe78(u8* object, f32* direction) {
    kn::FVector position;
    position = *(kn::FVector*)object;
    u8* info = *(u8**)(object + 0x5c);
    *(f32*)&position.y += *(f32*)(info + 8);
    u64 result = func_0016f000(*(s32*)(*(u8**)(object + 0x5c) + 4), (u8*)&position, func_002f8ad0(direction[0], direction[2]));
    if (result != 0) {
        func_0016c018(result, 1, *(u32*)(object + 0x58));
        D_003638d0 *= 0x10dcd;
        f32 value = (f32)D_003638d0;
        f32* scale = &D_0036e7bc;
        asm volatile("" : "+r"(scale)); // why: original forms the full address with lui+addiu and loads at offset 0 in this order (v2 folded %lo, v4 reordered)
        f32 product = value * *scale;
        register f32* range asm("$15") = &D_0036e7c0; // why: original reuses t7 for this address (v6 allocated t6)
        asm volatile("" : "+r"(range)); // why: original forms the full address with lui+addiu and loads at offset 0 in this order (v2 folded %lo, v4 reordered)
        register f32 limit asm("$f2") = *range; // why: original loads this factor into $f2 (v8 allocated $f0); float binding form as in accepted fm_boundary_typed.cpp
        product = product * limit;
        f32* base = &D_0036e7c4;
        asm volatile("" : "+r"(base)); // why: original forms the full address with lui+addiu and loads at offset 0 in this order (v2 folded %lo, v4 reordered)
        D_00352ad0 = *base + product;
    }
    return result;
}
