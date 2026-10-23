#include "../common/types.h"
extern "C" u64 func_001094e0(...);
extern "C" u32 func_00133c60(...);

bool func_00109788(u64 first, u64 second) {
    // why: original keeps first in s0 across the call; the asm operand makes the binding hold
    register u64 owner asm("$16") = first;
    // why: pins owner to its bound register
    asm("" : "+r"(owner));
    if (func_001094e0(second) == 0) {
        func_00133c60(owner, second, 0, 0, 0);
        return true;
    }
    return false;
}
