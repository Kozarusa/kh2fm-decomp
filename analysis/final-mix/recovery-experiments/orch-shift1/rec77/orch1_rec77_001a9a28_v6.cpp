#include "../common/types.h"

extern "C" void* D_0036d61c[];
static void* volatile keep;

void func_001a9a28(u32 mode, u32* src, s32* dst) {
    // why: keeps the body label address-taken so the code is not removed
    keep = &&body;
    if (mode < 6) {
        // why: original dispatches through the table at D_0036d61c
        goto *D_0036d61c[mode];
    body:
        *dst = *dst - *src;
        return;
    }
    return;
}
