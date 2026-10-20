#include "../common/types.h"
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(...);
extern "C" u8 func_00253918(...);
extern "C" u32 func_002539e8(...);

bool func_00259350(u32 value) {
    if (func_002538f8() != 0) return true;
    if (func_00253928(value) != 0) return true;
    if (func_00253918() != 0) return false;
    return func_002539e8(value, 0) == 0;
}
