#include "../common/types.h"

s32 func_0019c090(u8* object) {
    s32 result = 0;
    bool flag1 = (*(u32*)(*(u8**)(object + 0xc) + 8) & 1) != 0;
    if (!flag1) {
        u32 value = *(u32*)(object + 0x160);
        u8 flag2 = 0;
        if ((value & 0x20) != 0 || (value & 0x1000000) != 0) {
            flag2 = 1;
        }
        if (flag2 != 0) {
            return 1;
        }
        if ((*(u32*)(object + 0x108) & 0x800000) == 0) {
            return result;
        }
    }
    return 1;
}
