#include "../common/types.h"
extern "C" u8 D_00352b60[];
extern "C" void func_001e03b0(void*);
extern "C" void func_001e03d0(void*);

// Preserve original registry aliases.
void func_001e0750(s32 first, s32 second) asm("_Z16wtarget_001e0750jjjj");

void func_001e0750(s32 first, s32 second) {
    if (second == 0xffff && first == 1) {
        func_001e03b0(D_00352b60);
    }
    if (second == 0xffff && first == 0) {
        func_001e03d0(D_00352b60);
    }
}
