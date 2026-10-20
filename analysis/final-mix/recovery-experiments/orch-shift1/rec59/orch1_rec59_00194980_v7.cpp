#include "../common/types.h"

extern "C" u8* func_001947c0(u64, u64);
extern "C" s64 func_001a3570(u32);
extern "C" u8 D_01c61af4;

void func_00194980() {
    // why: original keeps the flag in s0 across both calls
    register s32 flag asm("$16") = 0;
    u8* entry = func_001947c0(-1, -1);
    u16 id = *(u16*)(entry + 0x32);
    if (id != 0 && func_001a3570(id) > 0) {
        flag = 1;
    }
    D_01c61af4 = flag;
}
