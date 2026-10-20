#include "../common/types.h"
extern "C" u64 func_001adf00();
extern "C" void func_003058a0(s32);

u64 func_001682b8() {
    // why: keeps the s0 save out of the call delay slot (original has nop there)
    asm volatile("" ::: "memory");
    u64 result = func_001adf00();
    func_003058a0(0);
    return result;
}
