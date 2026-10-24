#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

// Preserve original registry aliases.
u32 func_001d87b8(u32 index) asm("_ZN2YS7MISSION8GetCountEi");

u32 func_001d87b8(u32 index) {
    if (func_001bb4a0()) {
        u32* flags = (u32*)(func_001bbcb0() + index * 0x38 + 0xf4);
        if (*flags & 1) {
            return *(u32*)(func_001bbcb0() + index * 0x38 + 0x114);
        }
    }
    return 0;
}
