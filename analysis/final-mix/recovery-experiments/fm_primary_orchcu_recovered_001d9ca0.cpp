#include "../common/types.h"
extern "C" u8 D_01d5baa0[];
extern "C" void func_001d9a18(u8*, s32);

void func_001d9ca0(s32 mode, s32 id) {
    if (id == 0xffff && mode == 1) {
        func_001d9a18(D_01d5baa0, -1);
    }
}
