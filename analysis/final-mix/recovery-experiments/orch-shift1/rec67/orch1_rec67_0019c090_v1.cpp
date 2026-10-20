#include "../common/types.h"

s32 func_0019c090(u8* object) {
    bool flag1 = (*(u32*)(*(u8**)(object + 0xc) + 8) & 1) != 0;
    if (!flag1) {
        u32 value = *(u32*)(object + 0x160);
        u32 mask1 = 0x1000000;
        bool flag2;
        if ((value & 0x20) != 0 || (value & mask1) != 0) {
            flag2 = true;
        } else {
            flag2 = false;
        }
        if (flag2) {
            return 1;
        }
        u32 other = *(u32*)(object + 0x108);
        u32 mask2 = 0x800000;
        if ((other & mask2) == 0) {
            return 0;
        }
    }
    return 1;
}
