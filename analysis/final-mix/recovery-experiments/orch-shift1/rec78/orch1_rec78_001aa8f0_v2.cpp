#include "../common/types.h"
extern "C" void func_001ab260(f32, f32, u32, u32*, u64, u64, u64, u64, u32);

void func_001aa8f0(u32* object, u64 a, u64 b, u64 c, u64 d) {
    func_001ab260(((f32*)object)[9], ((f32*)object)[10], object[0], object + 16, a, b, c, d, object[14]);
    // why: empty barrier after the call blocks the tail-call (original uses jal and returns)
    asm volatile("" ::: "memory");
}
