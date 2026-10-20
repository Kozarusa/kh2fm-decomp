#include "../common/types.h"

extern "C" void* D_0036d61c[];

void func_001a9a28(u32 mode, u32* src, s32* dst) {
    if (mode < 6) {
        // why: original dispatches through the table at D_0036d61c; labels-as-values keeps the table external
        goto *D_0036d61c[mode];
    body:
        *dst = *dst - *src;
        return;
    }
    return;
    // why: keeps the body label address-taken so the code is not removed
    static void* keep = &&body;
}
