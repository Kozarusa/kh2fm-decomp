#include "../common/types.h"

s32 func_001d3f38(u8* object) {
    s32 id = *(u16*)(object + 0x28);
    switch (id) {
    case 0x11a:
    case 0x158:
    case 0x1e4:
        return 0;
    default:
        return 1;
    }
}
