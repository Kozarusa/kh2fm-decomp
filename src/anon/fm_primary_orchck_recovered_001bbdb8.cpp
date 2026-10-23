#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u8* func_001bbcb0(void);
extern "C" u32 func_001d4fa8(u8*, s32);

s32 func_001bbdb8(s32 value) {
    if (func_001bb4a0()) {
        if (*(u32*)(func_001bbcb0() + 0x2f0) & 4) {
            func_001d4fa8(func_001bbcb0() + 0x2e4, value);
            return 1;
        }
    }
    return 0;
}
