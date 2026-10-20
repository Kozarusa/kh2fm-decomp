#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" u32 D_0034f240;
extern "C" s32 D_01c61960;
extern "C" bool func_0019ba60(u64);
extern "C" bool func_001a6850(void);
extern "C" bool func_001b58a8(void);

bool func_001918c8() {
    if (!func_0019ba60(D_0034e948)) {
        D_01c61960 = 0;
        return false;
    }
    if (func_001b58a8()) {
        return true;
    }
    if ((D_0034f240 & 0x10000) != 0) {
        return true;
    }
    return func_001a6850() != 0;
}
