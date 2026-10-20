#include "../common/types.h"
extern "C" bool func_001bd590(u64);
extern "C" u32 func_001819c0(void);

u32 func_001bdcd0(u64 object) {
    u32 result = 0;
    if (func_001819c0() == 0 || func_001bd590(object)) {
        result = 1;
    }
    return result;
}
