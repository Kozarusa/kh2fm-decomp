#include "../common/types.h"
extern "C" u64 func_001094e0(...);
extern "C" u32 func_00133c60(...);

bool func_00109788(u64 first, u64 second) {
    // why: an extra use raises first's allocation priority so it takes s0
    asm("" : "+r"(first));
    if (func_001094e0(second) == 0) {
        func_00133c60(first, second, 0, 0, 0);
        return true;
    }
    return false;
}
