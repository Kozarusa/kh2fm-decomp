#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

bool func_001d8f38(s32 index) {
    bool result;
    if (func_001bb4a0()) {
        result = false;
        u32 word = *(u32*)(func_001bbcb0() + index * 0x34 + 0x19c);
        u8 flag = word & 1;
        if (flag) {
            u32 bit = *(u32*)(func_001bbcb0() + index * 0x34 + 0x19c) & 8;
            result = bit != 0;
        }
    } else {
        result = false;
    }
    return result;
}
