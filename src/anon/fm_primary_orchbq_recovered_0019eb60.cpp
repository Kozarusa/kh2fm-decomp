#include "../common/types.h"
extern "C" u64 D_0034ecc8;
extern "C" void func_0015ee90(s32);

// Preserve original registry aliases.
void func_0019eb60() asm("_ZN2YS4UNIT8ActivateEPc");

void func_0019eb60() {
    s32 index = 0;
    do {
        if (((D_0034ecc8 >> index) & 1) != 0) {
            func_0015ee90(index);
        }
        index = index + 1;
    } while (index < 64);
}
