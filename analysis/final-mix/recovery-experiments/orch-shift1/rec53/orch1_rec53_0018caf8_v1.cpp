#include "../common/types.h"

s32 func_0018caf8(u8* object) {
    switch (object[0x27]) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 0xf:
    case 0x10:
        return 1;
    default:
        return 0;
    }
}
