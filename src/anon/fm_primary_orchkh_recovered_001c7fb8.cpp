#include "../common/types.h"

extern "C" u8 D_00351e18[];
extern "C" u32 D_01d49960[];
// why: no accepted declaration; the original sets only a0 before the jal and ignores v0
extern "C" void func_0010b978(u32*);
// why: no accepted declaration exists; the four u32 arguments are register-derived (the only definition is a generic placeholder thunk), void because the result is unused
extern "C" void func_001e02a0(u32 a0, u32 a1, u32 a2, u32 a3);
// why: types copied from accepted fm_primary_queueepsilonprime_recovered_0010c7f0.cpp; extern "C" because the C++ name fails the isolated probe link (lg276 v1)
extern "C" void func_0010c7f0(u32* object);

// why: void per ruling #36: the only exit tail-calls func_0010c7f0, whose accepted definition is void (stale-b); accepted caller 001c88a8 also declares this function void

void func_001c7fb8(u32* object) {
    func_0010b978(object);
    object[0] = (u32)D_00351e18;
    object[354] |= 0x400000;
    object[474] &= ~0x10;
    s32 index;
    for (index = 0; index < 2; index++) {
        if (D_01d49960[index] == 0) {
            D_01d49960[index] = (u32)object;
            break;
        }
    }
    if (index > 0) {
        register u32 third asm("$6"); // why: the original leaves a2 untouched for the pass-through thunk (a caller-saved register clobbered by func_0010b978, so it cannot be a parameter)
        register u32 fourth asm("$7"); // why: the original leaves a3 untouched for the pass-through thunk
        asm("" : "=r"(third), "=r"(fourth)); // why: defines the untouched a2 and a3 without emitting code (one asm so they are not merged)
        func_001e02a0((u32)(object + 32), D_01d49960[0] + 0x80, third, fourth);
    }
    object[38] = 1;
    func_0010c7f0(object);
}
