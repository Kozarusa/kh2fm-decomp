#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

u32 func_001d9228(s32 index) {
    u32 result = 0;
    if (func_001bb4a0()) {
        u32 base = func_001bbcb0();
        result = 0;
        u8 flag = *(u32*)(base + index * 0x40 + 0x26c) & 1;
        if (flag) {
            base = func_001bbcb0();
            result = *(u32*)(base + index * 0x40 + 0x28c);
        }
    }
    return result;
}
