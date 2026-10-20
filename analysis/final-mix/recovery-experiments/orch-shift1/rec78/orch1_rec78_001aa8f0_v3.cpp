#include "../common/types.h"
extern "C" void func_001ab260(f32, f32, u32, u32*, s32, s32, s32, s32, u32);

void func_001aa8f0(u32* object, s32 a, s32 b, s32 c, s32 d) {
    u32 last = object[14];
    func_001ab260(((f32*)object)[9], ((f32*)object)[10], object[0], object + 16, a, b, c, d, last);
    // why: empty barrier after the call blocks the tail-call (original uses jal and returns)
    asm volatile("" ::: "memory");
}
