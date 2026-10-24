#include "../common/types.h"
extern "C" s8 D_01c60500;
extern "C" f32 D_01c60510[4];
extern "C" u8 D_0017bef8[];
extern "C" void func_002fd188(u8*);

// Preserve original registry aliases.
u32* func_0017a968(u32* out) asm("_Z16ctarget_0017a968jjjj");

u32* func_0017a968(u32* out) {
    if (D_01c60500 == 0) {
        f32 zero = 0.0f;
        volatile f32* vector = D_01c60510; // why: keeps store order
        D_01c60500 = 1;
        vector[3] = zero;
        vector[0] = zero;
        vector[1] = zero;
        vector[2] = zero;
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
