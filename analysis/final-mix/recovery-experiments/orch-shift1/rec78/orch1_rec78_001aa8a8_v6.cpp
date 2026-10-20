#include "../common/types.h"
extern "C" void func_001aafe8(f32, f32, u32, u32*, u64, u64, u64, u64);

void func_001aa8a8(u32* object, u64 a, u64 b, u64 c, u64 d) {
    func_001aafe8(((f32*)object)[9], ((f32*)object)[10], object[0], object + 16, a, b, c, d);
    // why: empty barrier after the call blocks the tail-call (original uses jal and returns)
    asm volatile("" ::: "memory");
}
