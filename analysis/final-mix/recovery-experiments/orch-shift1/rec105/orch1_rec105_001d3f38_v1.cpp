#include "../common/types.h"

s32 func_001d3f38(u8* object) {
    u16 id = *(u16*)(object + 0x28);
    if (id != 0x158) {
        if (id < 0x159) {
            if (id != 0x11a) {
                return 1;
            }
        } else if (id != 0x1e4) {
            return 1;
        }
    }
    return 0;
}