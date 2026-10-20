#include "../common/types.h"
extern "C" f32 D_004f3604,D_0036b3a8;
extern "C" char D_0034aa70;
extern "C" void func_00190128(void*);

void func_0015a768(s32 mode, s64 phase) {
    // why: pins the 0xffff guard constant in t7 (register 15) as the original does
    register s64 guard asm("$15") = 0xffff; asm("" : "+r"(guard));
    if (phase != guard) return;
    // why: pins the constant 1 in t7 as the original does
    register s32 one asm("$15") = 1; asm("" : "+r"(one));
    if (mode == one) {
        // why: pins the source pointer in t7 so the address is formed before the load
        register f32* source asm("$15") = &D_0036b3a8; asm("" : "+r"(source));
        D_004f3604 = *source;
    }
    guard = 0xffff; asm("" : "+r"(guard));
    if (phase != guard) return;
    one = 1; asm("" : "+r"(one));
    if (mode == one) func_00190128(&D_0034aa70);
}