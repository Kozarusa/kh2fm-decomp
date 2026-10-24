#include "../common/types.h"
extern "C" f32 D_01e2be10, D_01e2be14, D_00375870, D_00375874;

// Preserve original registry aliases.
void func_002cb188(s32 mode, s64 phase) asm("_Z16wtarget_002cb188jjjj");

void func_002cb188(s32 mode, s64 phase) {
    register s64 guard asm("$15") = 0xffff; asm("" : "+r"(guard)); // why: original compares against 0xffff held in t7
    if (phase != guard) return;
    register s32 one asm("$15") = 1; asm("" : "+r"(one)); // why: original compares against 1 held in t7
    if (mode == one) {
        register f32* source asm("$15") = &D_00375870; asm("" : "+r"(source)); // why: original forms the source address in t7 then lwc1 0(t7)
        D_01e2be10 = *source;
    }
    guard = 0xffff; asm("" : "+r"(guard)); // why: original reloads 0xffff into t7
    if (phase != guard) return;
    one = 1; asm("" : "+r"(one)); // why: original reloads 1 into t7
    if (mode == one) {
        register f32* source asm("$15") = &D_00375874; asm("" : "+r"(source)); // why: original forms the source address in t7 then lwc1 0(t7)
        D_01e2be14 = *source;
    }
}
