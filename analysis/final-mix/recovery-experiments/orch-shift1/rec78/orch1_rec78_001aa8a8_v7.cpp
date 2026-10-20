#include "../common/types.h"
extern "C" void func_001aafe8(f32, f32, u32, u32*, s32, s32, s32, s32);

void func_001aa8a8(u32* object, s32 a, s32 b, s32 c, s32 d) {
    u32* pointer = object + 16;
    f32 second = ((f32*)object)[10];
    func_001aafe8(((f32*)object)[9], second, object[0], pointer, a, b, c, d);
    // why: empty barrier after the call blocks the tail-call (original uses jal and returns)
    asm volatile("" ::: "memory");
}
