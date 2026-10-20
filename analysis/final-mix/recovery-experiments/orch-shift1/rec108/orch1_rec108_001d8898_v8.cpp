#include "../common/types.h"
extern "C" s32 func_001bb4a0();
extern "C" s32 func_001bbcb0();

s32 func_001d8898(s32 index) {
    // why: original keeps the result in v0, sharing it with the callee return
    register s32 result asm("$2");
    if (func_001bb4a0() == 0) {
        result = 0;
    } else {
        s32 base = func_001bbcb0();
        base += index * 0x38;
        bool flag = (*(u32*)(base + 0xf4) & 1) != 0;
        result = 0;
        if (flag) {
            base = func_001bbcb0();
            base += index * 0x38;
            u32 bits = *(u32*)(base + 0xf4) & 8;
            result = 0 < bits;
        }
    }
    return result;
}