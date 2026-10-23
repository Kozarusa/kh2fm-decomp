#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" u8* D_00347f80;
extern "C" u32 func_00106a18(...);
extern "C" u32 func_00106a60(...);

u32 func_00139c90() {
    Matrix* target = (Matrix*)(D_00347f80 + 32);
    asm("" : "+r"(target)); // why: hides the base so the copy addresses target directly
    Matrix* left = (Matrix*)func_00106a18(0);
    u32 base = func_00106a60(0);
    Matrix* right = base ? (Matrix*)(base + 16) : 0;
    Matrix product;
    // why: VU0 macro 4x4 matrix multiply, same sequence as accepted 002f3cd8/0013a178
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,16(%1); lqc2 $vf3,32(%1); lqc2 $vf4,48(%1); lqc2 $vf5,0(%2); lqc2 $vf6,16(%2); lqc2 $vf7,32(%2); lqc2 $vf8,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; vmulax.xyzw ACC,$vf1,$vf6x; vmadday.xyzw ACC,$vf2,$vf6y; vmaddaz.xyzw ACC,$vf3,$vf6z; vmaddw.xyzw $vf6,$vf4,$vf6w; vmulax.xyzw ACC,$vf1,$vf7x; vmadday.xyzw ACC,$vf2,$vf7y; vmaddaz.xyzw ACC,$vf3,$vf7z; vmaddw.xyzw $vf7,$vf4,$vf7w; vmulax.xyzw ACC,$vf1,$vf8x; vmadday.xyzw ACC,$vf2,$vf8y; vmaddaz.xyzw ACC,$vf3,$vf8z; vmaddw.xyzw $vf8,$vf4,$vf8w; sqc2 $vf5,0(%0); sqc2 $vf6,16(%0); sqc2 $vf7,32(%0); sqc2 $vf8,48(%0)"
                 : : "r"(&product), "r"(left), "r"(right) : "memory");
    if (target != &product) {
        volatile Quad* source = (volatile Quad*)&product;
        Quad* destination = (Quad*)target;
        // why: original copies through t0
        register Quad row0 asm("$8") = source[0];
        // why: original copies through t1
        register Quad row1 asm("$9") = source[1];
        // why: original copies through t2
        register Quad row2 asm("$10") = source[2];
        // why: original copies through t3
        register Quad row3 asm("$11") = source[3];
        // why: all four loads come before the stores
        asm("" : "+r"(row0), "+r"(row1), "+r"(row2), "+r"(row3));
        destination[1] = row1;
        destination[2] = row2;
        destination[3] = row3;
        destination[0] = row0;
    }
    return base;
}
