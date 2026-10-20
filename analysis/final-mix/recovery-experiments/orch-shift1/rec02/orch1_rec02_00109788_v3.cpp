#include "../common/types.h"
extern "C" u64 func_001094e0(...);
extern "C" u32 func_00133c60(...);

bool func_00109788(u64 first, u64 second) {
    // why: original keeps first in s0 and second in s1 across the call
    register u64 owner asm("$16") = first;
    register u64 item asm("$17") = second;
    if (func_001094e0(item) == 0) {
        func_00133c60(owner, item, 0, 0, 0);
        return true;
    }
    return false;
}
