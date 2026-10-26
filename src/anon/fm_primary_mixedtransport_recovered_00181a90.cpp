#include "../common/types.h"
// Preserve original registry aliases.
void func_00181a90(void) asm("_ZN2YS13TEST_PROGRESS8set_flagEi");
extern "C" void func_00181178(u32);
extern "C" u8 D_0032bb30[];
void func_00181a90(void) {
    func_00181178(18504);
    func_00181178(18505);
    D_0032bb30[12] = 18;
    D_0032bb30[13] = 18;
    D_0032bb30[14] = 99;
}

