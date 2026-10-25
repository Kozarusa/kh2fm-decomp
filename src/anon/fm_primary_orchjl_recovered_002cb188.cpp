#include "../common/types.h"
extern "C" f32 D_01e2be10, D_01e2be14;

// Preserve original registry aliases.
void func_002cb188(s32 mode, s64 phase) asm("_Z16wtarget_002cb188jjjj");

void func_002cb188(s32 mode, s64 phase) {
    if (phase == 0xffff && mode == 1) {
        D_01e2be10 = 1.1344639f;
    }
    if (phase == 0xffff && mode == 1) {
        D_01e2be14 = 1.8325956f;
    }
}
