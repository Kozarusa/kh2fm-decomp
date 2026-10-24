#include "../common/types.h"
extern "C" u8 D_003617e8;
extern "C" s32 D_003617e4;
extern "C" void func_002b8434(...);

// Preserve original registry aliases.
void func_002bd6d0(void) asm("_ZN2Tz9MenuSound14ResetPauseImplEv");

void func_002bd6d0(void) {
    if (D_003617e8 != 1) {
        s32 count = D_003617e4;
        if (count > 0) {
            s32 next = count - 1;
            D_003617e4 = next;
            if (next == 0) {
                func_002b8434(0);
            }
        }
    }
}
