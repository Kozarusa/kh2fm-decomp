#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" f32 D_004573f4;
extern "C" f32 D_004573f0;
extern "C" f32 D_0036adf4;
extern "C" f32 func_0017ce10(f32);
extern "C" void func_0011b6a8(void*);
extern "C" void func_0011b6d8(void*, f32);
extern "C" Matrix* func_0011b720(void*, f32);

Matrix* func_00140500(u8* object) {
    *(f32*)(object + 192) = func_0017ce10(*(f32*)(object + 192));
    f32 pitch = func_0017ce10(*(f32*)(object + 196));
    *(f32*)(object + 196) = pitch;
    if (D_004573f4 < pitch) {
        *(f32*)(object + 196) = D_004573f4;
    } else if (pitch < D_004573f0) {
        *(f32*)(object + 196) = D_004573f0;
    }
    kn::FVector direction;
    Matrix rotation;
    kn::FVector temp;
    f32* lanes = (f32*)&direction;
    const f32* height = &D_0036adf4;
    asm("" : "+r"(height)); // why: original forms the full address before the lwc1
    f32 zero = 0.0f;
    asm("" : "+f"(zero)); // why: original keeps the zero in $f0 and stores it with swc1
    lanes[2] = *height;
    lanes[0] = zero;
    lanes[1] = zero;
    lanes[3] = zero;
    func_0011b6a8(&rotation);
    func_0011b6d8(&rotation, *(f32*)(object + 196));
    Matrix* result = func_0011b720(&rotation, *(f32*)(object + 192));
    // why: VU0 macro vector times matrix, same sequence as accepted 0013a178/00139c90
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(&direction), "r"(&rotation) : "memory");
    direction = temp;
    kn::FVector* destination = (kn::FVector*)(object + 128);
    // why: VU0 macro vector add, accepted sibling pattern; destination is an unused input so its address is formed first
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&temp), "r"(object + 96), "r"(&direction), "r"(destination) : "memory");
    *destination = temp;
    return result;
}
