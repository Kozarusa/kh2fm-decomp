#include "../common/types.h"

s32 func_00186110(s32 unused, u8* object) {
    switch (object[36]) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}
