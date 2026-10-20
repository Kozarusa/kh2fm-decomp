#include "../common/types.h"
extern "C" f32 D_0036dfa8;
extern "C" void func_001c71f8(f32);
extern "C" void func_001c7440(s32, s32);

void func_001c73e0(s32 object) {
    func_001c71f8(D_0036dfa8);
    func_001c7440(object, 0);
    // why: prevents sibling-call optimisation, original uses jal plus its own return
    asm volatile("" ::: "memory");
}
