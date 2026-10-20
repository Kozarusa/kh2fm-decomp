#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001d9228(s32 index) {
    u32 result = 0;
    if (func_001bb4a0()) {
        u32 base = func_001bbcb0() + index * 0x40;
        u32 word = *(u32*)(base + 0x26c);
        u8 flag = word & 1;
        result = 0;
        if (flag) {
            u32 base2 = func_001bbcb0() + index * 0x40;
            result = *(u32*)(base2 + 0x28c);
        }
    }
    return result;
}
