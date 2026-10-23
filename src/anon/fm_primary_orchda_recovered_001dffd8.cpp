#include "../common/types.h"
extern "C" s32 D_00352b50;
extern "C" bool func_0019ba60(s32);

s32 func_001dffd8(s32 object) {
    s32 result = 0;
    if (D_00352b50 == 1) {
        s32 flag = 0;
        if (!func_0019ba60(*(s32*)(object + 0x48)) ||
            (*(u32*)(*(s32*)(object + 0x48) + 0x160) & 0x20000000) != 0 ||
            (*(u32*)(*(s32*)(object + 0x48) + 0x10c) & 0x400) != 0) {
            flag = 1;
        }
        result = flag;
    }
    return result;
}
