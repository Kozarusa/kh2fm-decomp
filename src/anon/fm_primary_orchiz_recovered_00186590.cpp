#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036c974;
extern "C" u16 D_0036c970[];
extern "C" s32 func_001860b0(const u8* object, const kn::FVector* plane);
extern "C" u32 func_0016aef0(u8*, kn::FVector*);
extern "C" s32 func_0017f4e0(u8*, u32);
extern "C" void func_0017f488(u8*, u32, f32, f32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);

s32 func_00186590(u8* object, kn::FVector* direction, s32 motion) {
    kn::FVector local;
    local = *direction;
    s32 index;
    s32 found = func_001860b0(object, direction);
    const f32* scale = &D_0036c974;
    asm("" : "+r"(scale)); // why: original forms the full address before the lwc1
    f32 factor = *scale;
    if (found != 0) {
        index = 0;
        // why: VU0 macro vector times scalar in place, same sequence as accepted 00159d30
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&local), "f"(factor) : "$8", "memory");
    } else {
        index = 1;
    }
    f32 zero = 0.0f;
    func_0016aef0(object, &local);
    u8* base = object + 0x140;
    if (func_0017f4e0(base, D_0036c970[index]) == 0) {
        index ^= 1;
    }
    func_0017f488(base, D_0036c970[index], zero, zero);
    s32 result = func_0017f5e0(base, motion, 0, zero, zero);
    *(u32*)((u8*)direction + 0x18) |= 1;
    return result;
}
