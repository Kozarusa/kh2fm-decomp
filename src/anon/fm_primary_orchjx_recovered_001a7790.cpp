#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Matrix {
    Quad rows[4];

    inline Matrix& operator=(const Matrix& rhs) {
        asm("lq $8, 0(%1); lq $9, 16(%1); lq $10, 32(%1); lq $11, 48(%1);"
            "sq $8, 0(%0); sq $9, 16(%0); sq $10, 32(%0); sq $11, 48(%0)"
            :
            : "r"(this), "r"(&rhs)
            : "t0", "t1", "t2", "t3", "memory");
        return *this;
    }
};
extern "C" u32 func_00106a18(...);
extern "C" u32 func_00106a60(...);
extern "C" Matrix* func_00106ad0(u32);
extern "C" void func_00146680(void* target, const void* source);
extern "C" u64 func_00146730(...);

u64 func_001a7790(u32 value) {
    Matrix object;
    Matrix view;
    Matrix product;
    view = *func_00106ad0(func_00106a18(1));
    u32 base = func_00106a60(1);
    Matrix* right = base ? (Matrix*)(base + 16) : 0;
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,16(%1); lqc2 $vf3,32(%1); lqc2 $vf4,48(%1); lqc2 $vf5,0(%2); lqc2 $vf6,16(%2); lqc2 $vf7,32(%2); lqc2 $vf8,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; vmulax.xyzw ACC,$vf1,$vf6x; vmadday.xyzw ACC,$vf2,$vf6y; vmaddaz.xyzw ACC,$vf3,$vf6z; vmaddw.xyzw $vf6,$vf4,$vf6w; vmulax.xyzw ACC,$vf1,$vf7x; vmadday.xyzw ACC,$vf2,$vf7y; vmaddaz.xyzw ACC,$vf3,$vf7z; vmaddw.xyzw $vf7,$vf4,$vf7w; vmulax.xyzw ACC,$vf1,$vf8x; vmadday.xyzw ACC,$vf2,$vf8y; vmaddaz.xyzw ACC,$vf3,$vf8z; vmaddw.xyzw $vf8,$vf4,$vf8w; sqc2 $vf5,0(%0); sqc2 $vf6,16(%0); sqc2 $vf7,32(%0); sqc2 $vf8,48(%0)"
                 : : "r"(&product), "r"(&view), "r"(right) : "memory");
    func_00146680(&object, &product);
    return func_00146730(&object, value) == 0;
}
