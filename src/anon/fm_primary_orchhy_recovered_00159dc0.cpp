#include "../common/types.h"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" u32 func_00106a18(...);
extern "C" u32 func_00106a60(...);
extern "C" s32* func_0013a178(...);

s32 func_00159dc0(const f32* vector, const s32* bounds) {
    Matrix* left = (Matrix*)func_00106a18(1);
    u32 base = func_00106a60(1);
    Matrix* right = base ? (Matrix*)(base + 16) : 0;
    Matrix product;
    // why: VU0 macro 4x4 matrix multiply, same sequence as accepted 00139c90
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,16(%1); lqc2 $vf3,32(%1); lqc2 $vf4,48(%1); lqc2 $vf5,0(%2); lqc2 $vf6,16(%2); lqc2 $vf7,32(%2); lqc2 $vf8,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; vmulax.xyzw ACC,$vf1,$vf6x; vmadday.xyzw ACC,$vf2,$vf6y; vmaddaz.xyzw ACC,$vf3,$vf6z; vmaddw.xyzw $vf6,$vf4,$vf6w; vmulax.xyzw ACC,$vf1,$vf7x; vmadday.xyzw ACC,$vf2,$vf7y; vmaddaz.xyzw ACC,$vf3,$vf7z; vmaddw.xyzw $vf7,$vf4,$vf7w; vmulax.xyzw ACC,$vf1,$vf8x; vmadday.xyzw ACC,$vf2,$vf8y; vmaddaz.xyzw ACC,$vf3,$vf8z; vmaddw.xyzw $vf8,$vf4,$vf8w; sqc2 $vf5,0(%0); sqc2 $vf6,16(%0); sqc2 $vf7,32(%0); sqc2 $vf8,48(%0)"
                 : : "r"(&product), "r"(left), "r"(right) : "memory");
    s32* point = func_0013a178(vector, &product);
    s32 flags = (point[0] < bounds[0]) << 2;
    if (bounds[1] < point[0]) flags |= 8;
    flags |= point[1] < bounds[2];
    if (bounds[3] < point[1]) flags |= 2;
    if (point[2] < 1) flags |= 0x10;
    if (4000000 < point[2]) flags |= 0x20;
    return flags;
}
