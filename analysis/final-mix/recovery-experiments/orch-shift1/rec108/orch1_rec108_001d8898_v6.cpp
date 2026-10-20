#include "../common/types.h"
extern "C" s32 func_001bb4a0();
extern "C" s32 func_001bbcb0();

s32 func_001d8898(s32 index) {
    if (func_001bb4a0() == 0) {
        return 0;
    }
    s32 base = func_001bbcb0();
    base += index * 0x38;
    bool flag = (*(u32*)(base + 0xf4) & 1) != 0;
    if (!flag) {
        return 0;
    }
    base = func_001bbcb0();
    base += index * 0x38;
    u32 bits = *(u32*)(base + 0xf4) & 8;
    return 0 < bits;
}