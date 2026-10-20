#include "../common/types.h"

s32 func_0018c528(u32 value) {
    s32 result = 0;
    if (value < 14) {
        switch (value) {
        case 2:
        case 4:
            result = 287;
            break;
        case 3:
            return 0;
        case 0:
        case 1:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        default:
            break;
        }
    }
    return result;
}