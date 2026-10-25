#include "../common/types.h"
extern "C" u8* D_0035f2cc;
extern "C" u32 func_00167f18(s32);
extern "C" u64 func_00242618(u64,s8);
// why: no recovered declaration exists; a0 and a1 are set before each jal and its result is not used
extern "C" void func_002854d8(u32 id, u32 flag);
extern "C" u32 func_00287bd0(u32,u64);
extern "C" u32 func_00287cc0(u32);

// why: void per DEVIATIONS #36: the two early exits leave the direct func_00167f18 pointer, the tail exit into func_00287cc0 (store-only) is stale-b

void func_00284fd8() {
    u8* state = (u8*)func_00167f18(0);
    u32 mode;
    if (*(s32*)(D_0035f2cc + 0x338) != 8) {
        return;
    }
    u64 input = *(u64*)(state + 8);
    if (input & 4) {
        func_00242618(8, 1);
        func_002854d8(0xceca, 0);
        mode = 1;
    } else {
        if (!(input & 8)) {
            return;
        }
        func_00242618(8, 1);
        func_002854d8(0xcecb, 1);
        mode = 2;
    }
    func_00287bd0(mode, 0);
    func_00287cc0(0);
}
