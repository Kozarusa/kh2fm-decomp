#include "../common/types.h"
s32 func_0028dd90(s32 value) {
    s32 result = 0;
    s32 remainder = value % 10;
    switch (remainder) {
    case 0: break;
    case 1: result = 2; break;
    case 2: result = 1; break;
    }
    return result;
}

