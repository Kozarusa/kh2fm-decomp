#include "../common/types.h"
extern "C" u32 D_01c608b8;
extern "C" u32 func_0016b0d0(void);
extern "C" u32 func_0019ba60(u32);

// Preserve original registry aliases.
u32 func_00185de0(void) asm("_Z16ctarget_00185de0jjjj");

u32 func_00185de0(void) {
    if (func_0019ba60(D_01c608b8) == 0) {
        return func_0016b0d0();
    }
    return D_01c608b8;
}
