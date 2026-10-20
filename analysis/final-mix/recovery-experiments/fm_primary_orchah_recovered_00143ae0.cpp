#include "../common/types.h"

extern "C" u32 D_00348804;
extern "C" u32 func_00141c18(...);
extern "C" u32 func_00141ff0(...);

void func_00143ae0(u32 first, u32 second, u32 third, u32 fourth) {
    func_00141c18(D_00348804, 0, 0, 0, 0);
    func_00141ff0(D_00348804, first, second, third, fourth);
    // why: empty asm after the call prevents the tail call (original uses jal and returns itself)
    asm volatile("" ::: "memory");
}
