#include "../common/types.h"
extern "C" u64 D_01dadc00[];
extern "C" void func_002fb928();
extern "C" u64 func_00233ce0();

// Preserve original registry aliases.
u64 func_00233c98() asm("_Z16u_call0_00233c98v");

u64 func_00233c98() {
    func_002fb928();
    s32 count = 256;
    u64* pointer = D_01dadc00;
    do {
        *pointer = 0;
        --count;
        ++pointer;
    } while (count > 0);
    return func_00233ce0();
}
