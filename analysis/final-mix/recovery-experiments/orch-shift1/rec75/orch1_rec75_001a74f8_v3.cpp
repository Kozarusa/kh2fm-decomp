#include "../common/types.h"
extern "C" u32 D_01c6cb78;
extern "C" u64 func_001b8e88();
extern "C" void func_0019c218(u32, u64);

void func_001a74f8() {
    u64 result = func_001b8e88();
    *(s32*)(D_01c6cb78 + 0x9b0) = 0;
    func_0019c218(D_01c6cb78, result);
    asm volatile("" ::: "memory"); // why: blocks tail call, original keeps jal plus epilogue
}
