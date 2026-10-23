#include "../common/types.h"
extern "C" void func_0013ee88(void*);
extern "C" u32 D_00349270;
extern "C" u8 D_00348698[];

// Preserve original registry aliases.
void func_0014a868(s32 a, s32 b) asm("_Z13func_0014a868ii");

void func_0014a868(s32 a, s32 b) {
    if (b == 0xffff && a == 1) {
        func_0013ee88(&D_00349270);
    }
    if (b == 0xffff && a == 0) {
        D_00349270 = (u32)D_00348698;
    }
}
