#include "../common/types.h"
extern "C" u32 func_002637e8(s64);
extern "C" u32 func_00287bc0(void);
u32 func_002638e0(s64 value) {
    u32 result = 0;
    switch (func_00287bc0()) {
    case 1: result = 1; break;
    case 10: result = 1; break;
    case 11:
        if (value >= 0) result = ~func_002637e8(value) >> 31;
        break;
    default: result = 1; break;
    }
    return result;
}
