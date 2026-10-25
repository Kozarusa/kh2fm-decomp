#include "../common/types.h"

s32 func_001e35f0(u8* object) {
    switch (object[168]) {
    case 2:
        return 1;
    case 4:
        return 2;
    case 6:
        return 3;
    case 8:
        return 4;
    case 10:
        return 5;
    case 12:
        return 6;
    default:
        return 0;
    }
}
