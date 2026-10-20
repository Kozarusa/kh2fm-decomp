#include "../common/types.h"

s32 func_00154ee8(u8* object) {
    s32 result = 0x43;
    switch (*(s32*)(object + 0x18)) {
    case 0:
        return 0x48;
    case 1:
        break;
    case 2:
        return 0x48;
    default:
        result = 0x48;
        break;
    }
    return result;
}