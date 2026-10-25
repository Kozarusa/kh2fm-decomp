#include "../common/types.h"
// why: 0x10fc0-byte block copied with aligned ld/sd in 64-byte steps, which the compiler only emits for a 16-byte aligned type
struct __attribute__((aligned(16))) BlockLarge {
    u64 data[0x10fc0 / 8];
};
// why: 0x828-byte blocks copied with ldl/ldr pairs, so the type is only 4-byte aligned
struct BlockTable {
    u32 data[0x828 / 4];
};
extern "C" BlockLarge D_01d499b0;
extern "C" BlockLarge D_0032bb30;
extern "C" BlockTable D_01d5a97c;
extern "C" BlockTable D_0034f250;
extern "C" BlockTable D_01d5b1a4;
extern "C" BlockTable D_0034fa78;
extern "C" u32 func_001ada38(s64);  // copied from accepted caller fm_primary_orchix_recovered_00179648.cpp
// why: no accepted source declares it; no argument registers are set before the call and its result is unused
extern "C" void func_001ba138();
// why: no accepted source declares it; no argument registers are set before the call and its result is unused
extern "C" void func_00242908();
// why: no accepted source declares it; its tail chain (1d5a20 -> 1d5a48) only stores, so it is declared void
extern "C" void func_00168fa8();

// why: void per DEVIATIONS #36; the only exit tail-calls func_00168fa8, whose chain ends in store-only 1d5a48 and whose last v0/$f0 writer (179bc8 chain) is followed by later calls (19ef60, 1d5a20): stale-a/stale-b

void func_001cd388() {
    D_0032bb30 = D_01d499b0;
    D_0034f250 = D_01d5a97c;
    D_0034fa78 = D_01d5b1a4;
    func_001ada38(8);
    func_001ba138();
    func_00242908();
    func_00168fa8();
}
