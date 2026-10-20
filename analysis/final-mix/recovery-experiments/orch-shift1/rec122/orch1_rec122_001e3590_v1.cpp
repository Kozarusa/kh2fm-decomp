#include "../common/types.h"

s32 func_001e3590(u8* object) {
    switch (object[168]) {
    case 1:
        return 1;
    case 3:
        return 2;
    case 5:
        return 3;
    case 7:
        return 4;
    case 9:
        return 5;
    case 11:
        return 6;
    default:
        return 0;
    }
}