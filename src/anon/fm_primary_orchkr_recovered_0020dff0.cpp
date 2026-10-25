#include "../common/types.h"

typedef unsigned int Quad __attribute__((mode(TI)));

extern "C" u8 D_00359150[];
extern "C" u32 D_003591c8;
extern "C" u8 D_01da8c40[];
// why: the callee's original leaves an integer in v0 on every exit and this target returns it; declaration copied from the used result in fm_primary_orchkq_recovered_001e72a8.cpp
extern "C" s32 func_002f25a0(u32, u32);
extern "C" void func_002f3918(u32, u32);
extern "C" void func_003058a0(u32);

// why: the only exit returns the final func_002f25a0 result untouched (direct), so the typed return is kept (clarification (iv))

// Preserve original registry aliases.
s32 func_0020dff0(void) asm("_Z13func_0020dff0Pv");

s32 func_0020dff0(void) {
    u8* packet = D_01da8c40;
    asm("" : "+r"(packet)); // why: original keeps the packet address in one register and stores at offsets from it
    Quad saved = *(Quad*)D_01da8c40;
    *(Quad*)D_01da8c40 = 0x70000008;
    *(u64*)(packet + 128) = D_00359150[0] | ((u64)D_00359150[1] << 8) | ((u64)D_00359150[2] << 16);
    *(u64*)(packet + 136) = 61;
    func_002f25a0(0, 0);
    func_003058a0(0);
    func_002f3918(D_003591c8, (u32)packet);
    s32 result = func_002f25a0(0, 0);
    *(Quad*)D_01da8c40 = saved;
    return result;
}
