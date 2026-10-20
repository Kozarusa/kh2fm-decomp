#include "../common/types.h"
extern "C" u32 D_01d49320;
extern "C" u64 func_001bb4a0(void);
extern "C" u64 func_001bba30(u32);

u64 func_001bba88(void) {
    if (func_001bb4a0() != 0) {
        return func_001bba30(D_01d49320);
    }
    return 0;
}
