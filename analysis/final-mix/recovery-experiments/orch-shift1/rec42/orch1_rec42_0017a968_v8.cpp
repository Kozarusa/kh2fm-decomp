#include "../common/types.h"
extern "C" s8 D_01c60500;
extern "C" f32 D_01c60510[4];
extern "C" u8 D_0017bef8[];
extern "C" void func_002fd188(u8*);

u32* func_0017a968(u32* out) {
    if (D_01c60500 == 0) {
        f32 zero = 0.0f;
        D_01c60500 = 1;
        D_01c60510[3] = zero;
        D_01c60510[2] = zero;
        D_01c60510[1] = zero;
        D_01c60510[0] = zero;
        func_002fd188(D_0017bef8);
    }
    // why: original copies the 16-byte vector with lq/sq through t0 without a self-assignment check
    asm("lq $8, 0(%1);"
        "sq $8, 0(%0);"
        :
        : "r"(out), "r"(D_01c60510)
        : "t0", "memory");
    return out;
}