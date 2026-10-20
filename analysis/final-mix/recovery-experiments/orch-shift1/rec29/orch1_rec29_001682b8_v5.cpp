#include "../common/types.h"
extern "C" s64 func_001adf00();
extern "C" void func_003058a0(s32);

s64 func_001682b8() {
    // why: keeps the prologue saves ahead of the call so the delay slot stays a nop
    asm volatile("" ::: "memory");
    s64 result = func_001adf00();
    // why: keeps the call order stable
    asm volatile("" ::: "memory");
    func_003058a0(0);
    return result;
}
