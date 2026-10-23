#include "../common/types.h"
extern "C" u8 D_01d5baa0[];
extern "C" void func_001d9a18(u8*, s32);

// Preserve original registry aliases.
void func_001d9ca0(s32 mode, s32 id) asm("_Z16wtarget_001d9ca0jjjj");

void func_001d9ca0(s32 mode, s32 id) {
    if (id == 0xffff && mode == 1) {
        func_001d9a18(D_01d5baa0, -1);
    }
}
