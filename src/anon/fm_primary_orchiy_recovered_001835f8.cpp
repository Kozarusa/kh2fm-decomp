#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" f32 D_0036c89c;
extern "C" void func_0011b6a8(void*);
extern "C" Matrix* func_0011b720(void*, f32);
extern "C" f32 func_0017ce10(f32);
extern "C" void func_0017ff68(kn::FVector*, u8*);
extern "C" void func_001835a0(u8*, f32);
extern "C" bool func_0019c400(u8*);
extern "C" bool func_001c0cd8(u8*);

kn::FVector* func_001835f8(kn::FVector* out, u8* object) {
    Matrix rotation;
    kn::FVector temp;
    if (func_001c0cd8(object)) {
        // why: VU macro zero-fill of a 16-byte vector, copied from accepted sibling func_00178570
        asm volatile(
            "vsub.xyzw $vf1,$vf0,$vf0;"
            "sqc2 $vf1,0(%0)" : : "r"(out) : "memory");
        return out;
    }
    u8* position = object + 0x140;
    // why: lq/sq copy primitive as in kn::FVector, the original copies through t0 without an alias check; noreorder keeps the sq out of the next branch delay slot
    asm(".set noreorder;"
        "lq $8, 0(%1);"
        "sq $8, 0(%0);"
        ".set reorder"
        :
        : "r"(&temp), "r"(object + 0x1f0)
        : "t0", "memory");
    *out = temp;
    if (func_0019c400(object)) {
        out->w = 0;
        // why: VU0 macro vector times matrix, same sequence as accepted 00140500
        asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                     : : "r"(&temp), "r"(out), "r"(object + 0x40) : "memory");
    } else {
        f32 w = *(f32*)&out->w;
        f32 zero = 0.0f;
        if (w != zero) {
            func_001835a0(object, w);
        }
        func_0011b6a8(&rotation);
        const f32* offset = &D_0036c89c;
        asm("" : "+r"(offset)); // why: original forms the full address before the lwc1
        f32 angle = *(f32*)(object + 0x55c) + *offset;
        func_0017ff68(&temp, position);
        angle -= *(f32*)&temp.w;
        func_0011b720(&rotation, func_0017ce10(angle));
        *(f32*)&out->w = zero;
        // why: VU0 macro vector times matrix, same sequence as accepted 00140500; noreorder keeps the sqc2 out of the branch delay slot
        asm volatile(".set noreorder; lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0); .set reorder"
                     : : "r"(&temp), "r"(out), "r"(&rotation) : "memory");
    }
    *out = temp;
    return out;
}
