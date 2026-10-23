#include "../common/types.h"
extern "C" u32 D_00361f60;
extern "C" void func_002ceb08();
extern "C" s32 func_002e26c0(u32);

// Preserve original registry aliases.
s32 func_002e2d18() asm("_ZN2Ti12MG_EHSidecar17MoveToBeforePointEv");

s32 func_002e2d18() {
    u32 object = D_00361f60;
    if (object != 0) {
        func_002ceb08();
    }
    return func_002e26c0(object);
}
