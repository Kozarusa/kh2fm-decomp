#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

s32 func_001d87b8(s32 index) {
    if (!func_001bb4a0()) {
        return 0;
    }
    u32 word = *(u32*)(func_001bbcb0() + index * 0x38 + 0xf4);
    u8 flag = word & 1;
    if (!flag) {
        return 0;
    }
    return *(s32*)(func_001bbcb0() + index * 0x38 + 0x114);
}
