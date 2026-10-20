#include "../common/types.h"
extern "C" s64 func_001688b8();
extern "C" s64 func_002ba200();
extern "C" u64 func_00170c50();

u64 func_00170cd0() {
    s64 value = func_001688b8();
    u64 result;
    if (value != 0 || (value = func_002ba200(), value != 0)) {
        result = 1;
    } else {
        result = func_00170c50();
    }
    return result;
}
