#include "../common/types.h"
extern "C" u32 D_01d49320;
extern "C" bool func_001bb4a0(void);
extern "C" u64 func_001bba30(u32);

u64 func_001bba88(void) {
    u64 result = 0;
    if (func_001bb4a0()) {
        result = func_001bba30(D_01d49320);
    }
    return result;
}
