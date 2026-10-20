#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001d9228(s32 index) {
    if (!func_001bb4a0()) {
        return 0;
    }
    u32 base = func_001bbcb0() + index * 0x40;
    u8 flag = *(u32*)(base + 0x26c) & 1;
    if (!flag) {
        return 0;
    }
    return *(u32*)(func_001bbcb0() + index * 0x40 + 0x28c);
}
