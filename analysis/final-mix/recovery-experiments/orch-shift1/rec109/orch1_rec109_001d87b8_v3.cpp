#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

s32 func_001d87b8(s32 index) {
    s32 result;
    result = 0;
    if (func_001bb4a0()) {
        result = 0;
        u32 word = *(u32*)(func_001bbcb0() + index * 0x38 + 0xf4);
        u8 flag = word & 1;
        if (flag) {
            result = *(s32*)(index * 0x38 + func_001bbcb0() + 0x114);
        }
    }
    return result;
}
