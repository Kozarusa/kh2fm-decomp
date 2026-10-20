#include "../common/types.h"
extern "C" void func_001ab260(f32, f32, u32, u32*, s32, s32, s32, s32, u32);

void func_001aa8f0(u32* object, s32 a, s32 b, s32 c, s32 d) {
    // why: original keeps the argument copies in t6, t5, t4 (descending)
    register s32 copy_a asm("$14") = a;
    register s32 copy_b asm("$13") = b;
    register s32 copy_c asm("$12") = c;
    register s32 copy_d asm("$9") = d;
    // why: forces the bound registers to be honored
    asm("" : "+r"(copy_a));
    asm("" : "+r"(copy_b));
    asm("" : "+r"(copy_c));
    asm("" : "+r"(copy_d));
    u32 last = object[14];
    func_001ab260(((f32*)object)[9], ((f32*)object)[10], object[0], object + 16, copy_a, copy_b, copy_c, copy_d, last);
    // why: empty barrier after the call blocks the tail-call (original uses jal and returns)
    asm volatile("" ::: "memory");
}
