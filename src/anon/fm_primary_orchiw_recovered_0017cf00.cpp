#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef unsigned int Quad __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" f32 D_0036c54c;
extern "C" u32 func_00106a18(...);
extern "C" u32 func_00106a60(...);

kn::FVector* func_0017cf00(kn::FVector* out, const kn::FVector* in) {
    // why: original copies the input through t0 with lq/sq, plain Quad copy schedules differently
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(out), "r"(in) : "$8", "memory");
    const f32* source = &D_0036c54c;
    asm("" : "+r"(source)); // why: original forms the full address before the lwc1
    f32 one = *source;
    f32* lanes = (f32*)out;
    lanes[3] = one;
    Matrix* left = (Matrix*)func_00106a18(1);
    u32 base = func_00106a60(1);
    Matrix* right = base ? (Matrix*)(base + 16) : 0;
    kn::FVector temp;
    Matrix product;
    // why: VU0 macro 4x4 matrix multiply, same sequence as accepted 00139c90
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,16(%1); lqc2 $vf3,32(%1); lqc2 $vf4,48(%1); lqc2 $vf5,0(%2); lqc2 $vf6,16(%2); lqc2 $vf7,32(%2); lqc2 $vf8,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; vmulax.xyzw ACC,$vf1,$vf6x; vmadday.xyzw ACC,$vf2,$vf6y; vmaddaz.xyzw ACC,$vf3,$vf6z; vmaddw.xyzw $vf6,$vf4,$vf6w; vmulax.xyzw ACC,$vf1,$vf7x; vmadday.xyzw ACC,$vf2,$vf7y; vmaddaz.xyzw ACC,$vf3,$vf7z; vmaddw.xyzw $vf7,$vf4,$vf7w; vmulax.xyzw ACC,$vf1,$vf8x; vmadday.xyzw ACC,$vf2,$vf8y; vmaddaz.xyzw ACC,$vf3,$vf8z; vmaddw.xyzw $vf8,$vf4,$vf8w; sqc2 $vf5,0(%0); sqc2 $vf6,16(%0); sqc2 $vf7,32(%0); sqc2 $vf8,48(%0)"
                 : : "r"(&product), "r"(left), "r"(right) : "memory");
    // why: VU0 macro vector times matrix, same sequence as accepted 00140500
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(out), "r"(&product) : "memory");
    *out = temp;
    f32 scale = one / lanes[3];
    lanes[0] *= scale;
    lanes[1] *= scale;
    lanes[2] *= scale;
    lanes[3] = one;
    return out;
}
