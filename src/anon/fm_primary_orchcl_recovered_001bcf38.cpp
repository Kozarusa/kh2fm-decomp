#include "../common/types.h"

s32 func_001bcf38(s32* pointer) {
    switch (*pointer) {
    case 5:
    case 10:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 1;
    default:
        return 0;
    }
}
